/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** placer
*/

#include "struct.h"
#include <stddef.h>

void is_champion_size_correct(virtual_t *data);

static int is_placement_correct(champion_t *one, champion_t *two, long address)
{
    for (long j = one->address; j < one->address + one->size; ++j)
        if (j >= address && j <= address + two->size)
            return 0;
    return 1;
}

int place_champ(virtual_t *data, champion_t *champion, long address)
{
    if (data->champions == NULL)
        return 1;
    for (int i = 0; data->champions[i] != NULL; ++i) {
        if (data->champions[i]->address == -1)
            continue;
        if (!is_placement_correct(data->champions[i], champion, address))
            return 0;
    }
    return 1;
}

static void place_champions_correctly(virtual_t *data, long space)
{
    long address = 0;

    for (int i = 0; data->champions[i]; ++i) {
        if (data->champions[i]->address == -1) {
            for (; !place_champ(data, data->champions[i], address); ++address);
            address += (address == 0) ? 0 : space;
            place_champ_n(data, data->champions[i], address);
            address += data->champions[i]->size;
        }
    }
}

void place_champ_n(virtual_t *data, champion_t *champion, long address)
{
    for (long i = 0; i < champion->size; ++i)
        data->memory[select_address(i + address)] = champion->content[i];
    champion->address = address;
}

void place_champions(virtual_t *virtual)
{
    long size_taken = MEM_SIZE;

    is_champion_size_correct(virtual);
    if (!virtual->champions)
        return;
    for (int i = 0; virtual->champions[i]; ++i) {
        if (virtual->champions[i]->address != -1 && !place_champ(virtual,
            virtual->champions[i], virtual->champions[i]->address))
            error_exit("[ERROR] - Champions placement failed\n");
        if (virtual->champions[i]->address != -1) {
            size_taken -= virtual->champions[i]->size;
            place_champ_n(virtual, virtual->champions[i],
                        virtual->champions[i]->address);
        }
    }
    place_champions_correctly
        (virtual, size_taken / get_champions_size(virtual));
}
