/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** tools
*/

#include "struct.h"
#include <stdio.h>

int get_cmd_address(champion_t *champion)
{
    return select_address(champion->address + champion->pc);
}

int get_command_duration(int id)
{
    if (id < 1 || id > 16)
        return -1;
    return COMMANDS[id - 1].duration;
}

void add_pc(int *pc, int nb)
{
    *pc += nb;
    while (*pc > 65535)
        *pc -= 65536;
    while (*pc < 0)
        *pc += 65536;
}

int get_type_size(char type)
{
    if (type == DIR4)
        return (DIR4);
    if (type == DIR2)
        return (DIR2);
    if (type == REG)
        return (T_REG);
    if (type == IND)
        return (T_IND);
    return (0);
}
