/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** tools
*/

#include "struct.h"

int select_address(long address)
{
    while (address >= MEM_SIZE)
        address -= MEM_SIZE;
    while (address < 0)
        address += MEM_SIZE;
    return (address);
}

int memory_four_bytes(virtual_t *virtual, long address)
{
    int value = virtual->memory[select_address(address)];

    for (int i = 1; i < 4; ++i)
        value = (value << 8) + virtual->memory[select_address(address + i)];
    return value;
}

int memory_two_byes(virtual_t *virtual, long address)
{
    int value = virtual->memory[select_address(address)] & 255;

    value = ((value << 8) & 65280) +
            (virtual->memory[select_address(address + 1)] & 255);
    return value;
}
