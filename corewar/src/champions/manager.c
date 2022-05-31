/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** manager
*/

#include "struct.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void add_champion(virtual_t *data, champion_t *champion)
{
    int size = get_champions_size(data);
    champion_t **champs = malloc(sizeof(champion_t *) * (size + 2));

    if (champs == NULL)
        error_exit("[ERROR-add_champion] - Malloc failed\n");
    champs[size] = champion;
    champs[size + 1] = NULL;
    if (data->champions == NULL || data->champions[0] == NULL) {
        data->champions = champs;
        return;
    }
    for (int i = 0; i < size; ++i)
        champs[i] = data->champions[i];
    if (data->champions != NULL)
        free(data->champions);
    data->champions = champs;
}

void remove_champion(virtual_t *data, champion_t *champion)
{
    int counter = 0;
    int size = get_champions_size(data);
    champion_t **new = malloc(sizeof(champion_t *) * size);

    if (data->champions == NULL)
        return;
    for (int i = 0; data->champions[i]; ++i) {
        if (data->champions[i] != champion) {
            new[counter] = data->champions[i];
            ++counter;
        }
    }
    free(champion->content);
    free(champion->registers);
    free(champion);
    new[counter] = NULL;
    free(data->champions);
    data->champions = new;
}

champion_t *create_champion_copy(virtual_t *virtual, champion_t *champion)
{
    champion_t *new = malloc(sizeof(champion_t));

    if (new == NULL)
        error_exit("[ERROR-create_champion_copy] - Malloc failed\n");
    new->carry = champion->carry;
    my_strcpy(new->comment, champion->comment);
    new->content = malloc(sizeof(char) * champion->size);
    for (int i = 0; i < champion->size; ++i)
        new->content[i] = virtual->memory[
                select_address(champion->address + i)];
    new->id = champion->id;
    new->last_used = champion->last_used;
    new->cycle_of_live = champion->cycle_of_live;
    my_strcpy(new->name, champion->name);
    new->registers = malloc(sizeof(int) * (REG_NUMBER + 1));
    for (int i = 0; i < REG_NUMBER && champion->registers[i]; ++i)
        new->registers[i] = champion->registers[i];
    new->size = champion->size;
    return new;
}
