/*
** EPITECH PROJECT, 2022
** loop.c
** File description:
** loop
*/

#include "struct.h"

int get_command_duration(int id);

void cmd_ldi(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    char args[3] = {get_arg_type(virtual, address, 1),
                            get_arg_type(virtual, address, 2), REG};
    int one_size = get_type_size(args[0]);
    int value = memory_four_bytes(virtual, address +
        (get_arg_value_mod(virtual, args[0], address + 2, champion) +
        get_arg_value_mod(virtual, args[1], address + 2 + one_size,
        champion)) % IDX_MOD);

    champion->registers[virtual->memory[
        select_address(address + 2 + one_size + get_type_size(args[1]))] - 1]
        = value;
    champion->carry = (value == 0) ? 1 : 0;
    write_new_pc(champion, args, 1);
}

void cmd_sti(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    char args[3] = {REG, get_arg_type(virtual, address, 2),
                            get_arg_type(virtual, address, 3)};
    long reg = get_arg_value_mod(virtual, REG, address + 2, champion);

    write_four_bytes(virtual,
        address + (get_arg_value_mod(virtual, args[1], address + 3, champion)
        + get_arg_value_mod(virtual, args[2], address + 3 +
        get_type_size(args[1]), champion)) % IDX_MOD, reg);
    champion->carry = (reg == 0) ? 1 : 0;
    write_new_pc(champion, args, 1);
}

void cmd_fork(virtual_t *virtual, champion_t *champion)
{
    int address = get_cmd_address(champion);
    int arg = get_arg_value(virtual, DIR2, address + 1, champion);
    champion_t *new = create_champion_copy(virtual, champion);

    new->address = address + champion->size + arg % IDX_MOD;
    new->pc = champion->pc + arg % IDX_MOD;
    place_champ_n(virtual, new, new->address);
    add_champion(virtual, new);
    add_pc(&champion->pc, 3);
}

void cmd_lld(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    char args[3] = {get_arg_type(virtual, address, 1), REG,
                            NO};
    long one = get_arg_value(virtual, args[0], address + 2, champion);
    int reg = virtual->memory[
        select_address(address + 2 + get_type_size(args[0]))];

    champion->registers[reg - 1] = one;
    champion->carry = (one == 0) ? 1 : 0;
    write_new_pc(champion, args, 1);
}
