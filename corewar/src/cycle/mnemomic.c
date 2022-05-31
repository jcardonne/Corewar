/*
** EPITECH PROJECT, 2022
** loop.c
** File description:
** loop
*/

#include "struct.h"

int get_command_duration(int id);

void cmd_ld(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    char args[3] = {get_arg_type(virtual, address, 1), REG,
                    NO};
    long one = get_arg_value_mod(virtual, args[0], address + 2, champion);

    champion->registers[virtual->memory[select_address(address + 2 +
        get_type_size(args[0]))] - 1] = one;
    champion->carry = one == 0 ? 1 : 0;
    write_new_pc(champion, args, 1);
}

void cmd_st(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    char args[3] = {REG, get_arg_type(virtual, address, 2), NO};
    int reg = get_arg_value_mod(virtual, REG, address + 2, champion);
    int two = get_arg_value_mod(virtual, args[1], address + 3, champion);

    if (args[1] == REG) {
        two = virtual->memory[select_address(address + 3)];
        champion->registers[two - 1] = reg;
    } else
        write_four_bytes(virtual, select_address(address + two % IDX_MOD),
                    reg);
    champion->carry = (reg == 0) ? 1 : 0;
    write_new_pc(champion, args, 1);
}

void cmd_add(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    int reg = virtual->memory[select_address(address + 4)];
    long result = get_arg_value(virtual, REG, address + 2, champion)
        + get_arg_value(virtual, REG, address + 3, champion);

    champion->registers[reg - 1] = result;
    champion->carry = (result == 0) ? 1 : 0;
    add_pc(&champion->pc, 5);
}

void cmd_sub(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    int reg = virtual->memory[select_address(address + 4)];
    long result = get_arg_value(virtual, REG, address + 2, champion)
        - get_arg_value(virtual, REG, address + 3, champion);

    champion->registers[reg - 1] = result;
    champion->carry = (result == 0) ? 1 : 0;
    add_pc(&champion->pc, 5);
}
