/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** manager
*/

#include "struct.h"

static int is_args_valid(int cmd, int one, int two, int three)
{
    int is_different_one = COMMANDS[cmd].args_types[0].one != one
        && COMMANDS[cmd].args_types [0].two != one &&
        COMMANDS[cmd].args_types[0].three != one;
    int is_different_two = COMMANDS[cmd].args_nbr > 1 &&
        COMMANDS[cmd].args_types[1].one != two
        && COMMANDS[cmd].args_types[1].two != two
        && COMMANDS[cmd].args_types[1].three != two;
    int is_different_three = COMMANDS[cmd].args_nbr > 2
        && COMMANDS[cmd].args_types[2].one != three
        && COMMANDS[cmd].args_types[2].two != three
        && COMMANDS[cmd].args_types[2].three != three;

    if (is_different_one || is_different_two || is_different_three)
        return 0;
    return 1;
}

static int is_ocp(virtual_t *virtual, long address)
{
    int cmd = virtual->memory[select_address(address)] - 1;

    if (!COMMANDS[cmd].has_op_code)
        return 1;
    int one = get_arg_type(virtual, address, 1);
    int two = get_arg_type(virtual, address, 2);
    int three = get_arg_type(virtual, address, 3);
    if (!is_args_valid(cmd, one, two, three))
        return 0;
    return 1;
}

static int get_cmd_type(virtual_t *virtual, long address, int cmd, int arg)
{
    if (!COMMANDS[cmd].has_op_code ||
        get_arg_type(virtual, address, arg) == NO)
        return get_type_size(COMMANDS[cmd].args_types[arg - 1].one);

    return get_type_size(get_arg_type(virtual, address, arg));
}

static int is_reg(virtual_t *virtual, long address)
{
    int cmd = virtual->memory[select_address(address)] - 1;
    long new_addy = address + 2;

    if (!COMMANDS[cmd].has_op_code)
        --new_addy;
    for (int i = 0; i < COMMANDS[cmd].args_nbr; ++i) {
        if (get_cmd_type(virtual, address, cmd, i + 1) == T_REG &&
            (virtual->memory[select_address(new_addy)] > 16 ||
            virtual->memory[select_address(new_addy)] < 1))
            return 0;
        new_addy += get_cmd_type(virtual, address, cmd, i + 1);
    }
    return 1;
}

int is_cmd(virtual_t *virtual, long address)
{
    int cmd = virtual->memory[select_address(address)];

    if (cmd < 1 || cmd > 16 || !is_ocp(virtual, address)
        || !is_reg(virtual, address))
        return 0;
    return 1;
}
