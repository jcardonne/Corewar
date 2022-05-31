/*
** EPITECH PROJECT, 2022
** loop.c
** File description:
** loop
*/

#include "struct.h"

int get_command_duration(int id);

char get_arg_type(virtual_t *virtual, long address, int arg)
{
    int cmd = virtual->memory[select_address(address)] - 1;
    int ocp = virtual->memory[select_address(address + 1)];
    int result = (ocp >> 6) & 3;

    if (arg == 2)
        result = (ocp >> 4) & 3;
    if (arg == 3)
        result = (ocp >> 2) & 3;
    for (int i = 0; i < 3; ++i) {
        if (COMMANDS[cmd].args_types[i].one == DIR4 ||
            COMMANDS[cmd].args_types[i].two == DIR4 ||
            COMMANDS[cmd].args_types[i].three == DIR4)
            result = result == DIR2 ? DIR4 : result;
    }
    if (!COMMANDS[cmd].has_op_code || result == NO)
        return (COMMANDS[cmd].args_types[arg - 1].one);
    return result;
}

int get_arg_value(virtual_t *virtual, char type,
                    long address, champion_t *champion)
{
    if (type == REG)
        return champion->registers[virtual->memory[select_address(address)]
        - 1];
    if (type == IND)
        return memory_four_bytes(virtual, select_address(
                memory_two_byes(virtual, address) + champion->address +
                champion->pc));
    if (type == DIR2)
        return memory_two_byes(virtual, address);
    return memory_four_bytes(virtual, address);
}

int get_arg_value_mod(virtual_t *virtual, char type, long address,
                        champion_t *champion)
{
    if (type == REG)
        return champion->registers[virtual->memory[select_address(address)]
        - 1];
    if (type == IND)
        return memory_four_bytes(virtual, select_address(
                memory_two_byes(virtual, address) % IDX_MOD +
                champion->address + champion->pc));
    if (type == DIR2)
        return memory_two_byes(virtual, address);
    return memory_four_bytes(virtual, address);
}
