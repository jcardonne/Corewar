/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** tools
*/

#include "struct.h"
#include <stdlib.h>

void is_champion_size_correct(virtual_t *data)
{
    long size = 0;

    for (int i = 0; data->champions[i]; ++i)
        size += data->champions[i]->size;
    if (MEM_SIZE < size)
        error_exit("[ERROR-isChampionSizeCorrect] - The .cor too long\n");
}

int get_champions_size(virtual_t *virtual)
{
    int size = 0;

    if (virtual->champions == NULL)
        return 0;
    for (; virtual->champions[size] != NULL; ++size);
    return size;
}

void funeral_service(virtual_t *data, int dead)
{
    int redo = 0;

    if (data->champions == NULL)
        return;
    for (int i = 0; data->champions[i]; ++i) {
        if (dead == 1 && absolute(data->cycle -
        data->champions[i]->cycle_of_live) >
            data->cycle_to_die) {
            remove_champion(data, data->champions[i]);
            redo = 1;
            break;
        }
        if (dead == 0)
            remove_champion(data, data->champions[i]);
    }
    if (dead == 1 && redo)
        funeral_service(data, dead);
}

void swap_champions(virtual_t *virtual, int old_index, int new_index)
{
    champion_t *temp = virtual->champions[old_index];

    virtual->champions[old_index] = virtual->champions[new_index];
    virtual->champions[new_index] = temp;
}
