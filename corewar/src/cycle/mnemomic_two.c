/*
** EPITECH PROJECT, 2022
** loop.c
** File description:
** loop
*/

#include "struct.h"

int get_command_duration(int id);

void cmd_and(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    char args[3] = {get_arg_type(virtual, address, 1),
                            get_arg_type(virtual, address, 2), REG};
    int one_size = get_type_size(args[0]);
    int two_size = get_type_size(args[1]);
    int reg = virtual->memory[
        select_address(address + 2 + one_size + two_size)];
    long result = get_arg_value_mod(
        virtual, args[0], address + 2, champion) & get_arg_value_mod(
            virtual, args[1], address + 2 + one_size, champion);

    champion->registers[reg - 1] = result;
    champion->carry = (result == 0) ? 1 : 0;
    write_new_pc(champion, args, 1);
}

void cmd_or(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    char args[3] = {get_arg_type(virtual, address, 1),
                            get_arg_type(virtual, address, 2), REG};
    int one_size = get_type_size(args[0]);
    int two_size = get_type_size(args[1]);
    long result = get_arg_value_mod(virtual, args[0], address + 2, champion) |
        get_arg_value_mod(virtual, args[1], address + 2 + one_size, champion);

    champion->registers[virtual->memory[
        select_address(address + 2 + one_size + two_size)] - 1] = result;
    champion->carry = (result == 0) ? 1 : 0;
    write_new_pc(champion, args, 1);
}

void cmd_xor(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    char args[3] = {get_arg_type(virtual, address, 1),
                            get_arg_type(virtual, address, 2), REG};
    int one_size = get_type_size(args[0]);
    int two_size = get_type_size(args[1]);
    long result = get_arg_value_mod
    (virtual, args[0], address + 2, champion) ^ get_arg_value_mod(
        virtual, args[1], address + 2 + one_size, champion);

    champion->registers[virtual->memory[
        select_address(address + 2 + one_size + two_size)] - 1] = result;
    champion->carry = (result == 0) ? 1 : 0;
    write_new_pc(champion, args, 1);
}

void cmd_zjmp(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);

    if (champion->carry)
        add_pc(&champion->pc, memory_two_byes(virtual, address + 1));
    else
        add_pc(&champion->pc, 3);
}
