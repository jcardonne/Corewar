/*
** EPITECH PROJECT, 2022
** loop.c
** File description:
** loop
*/

#include "struct.h"
#include "my.h"
#include <stdlib.h>

void funeral_service(virtual_t *data, int dead);
void swap_champions(virtual_t *virtual, int old_index, int new_index);
void run_cmds(virtual_t *data);

static int sort_champions_two(virtual_t *virtual)
{
    int result = 1;
    int len = get_champions_size(virtual);

    for (int i = 0; i <= len; ++i) {
        if (virtual->champions[i] != NULL && virtual->champions[i + 1] != NULL
            && virtual->champions[i + 1]->id < virtual->champions[i]->id) {
            swap_champions(virtual, i, i + 1);
            result = 0;
        }
    }
    return result;
}

static void sort_champions(virtual_t *virtual)
{
    if (virtual->champions == NULL)
        return;
    while (!sort_champions_two(virtual));
}

static void fight_result(virtual_t *data)
{
    if (!data->last_alive) {
        my_putstr("Draw!\n");
    } else if (data->last_alive != NULL) {
        my_putstr_two(data->last_alive, " (");
        my_put_nbr_long(data->last_live_id);
        my_putstr(") won the fight\n");
        free(data->last_alive);
    } else {
        my_putstr("No champion won the fight\n(unable to display winner)\n");
    }
}

void loop(virtual_t *data)
{
    while (!(data->cycle_dump > 0 && data->cycle >= data->cycle_dump) &&
        get_champions_size(data) >= 1) {
        sort_champions(data);
        run_cmds(data);
        funeral_service(data, 1);
        ++data->cycle;
    }
    fight_result(data);
}
