/*
** EPITECH PROJECT, 2022
** init_data.c
** File description:
** init_data
*/

#include "struct.h"
#include <stdlib.h>
#include <unistd.h>

void init_data_two(virtual_t *virtual)
{
    virtual->args = malloc(sizeof(args_t));
    virtual->memory = malloc(sizeof(int) * MEM_SIZE);
    virtual->champions = NULL;
    virtual->nb_champions = 0;
    virtual->args->dump = 0;
    virtual->args->load_address = 0;
    virtual->args->prog_number = -1;
    virtual->cycle_dump = -1;
    virtual->cycle = 0;
    virtual->cycle_to_die = CYCLE_TO_DIE;
    virtual->last_alive = NULL;
    virtual->last_live_id = -1;
    virtual->live_calls = 0;
}
