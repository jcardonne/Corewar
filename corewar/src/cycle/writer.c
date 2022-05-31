/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** writer
*/

#include "struct.h"

void write_four_bytes(virtual_t *virtual, long address, int value)
{
    int one = (value >> 24) & 255;
    int two = (value >> 16) & 255;
    int three = (value >> 8) & 255;
    int four = value & 255;

    virtual->memory[select_address(address)] = one;
    virtual->memory[select_address(address + 1)] = two;
    virtual->memory[select_address(address + 2)] = three;
    virtual->memory[select_address(address + 3)] = four;
}

void write_new_pc(champion_t *champion, const char args[3], int has_ocp)
{
    int add = 1;

    for (int i = 0; i < 3; ++i) {
        if (args[i] == NO)
            continue;
        add = args[i] == REG ? add + T_REG : add;
        add = args[i] == IND ? add + T_IND : add;
        add = args[i] == DIR2 ? add + T_DIR : add;
        add = args[i] == DIR4 ? add + T_IND : add;
    }
    add = has_ocp ? add + 1 : add;
    add_pc(&champion->pc, add);
}
