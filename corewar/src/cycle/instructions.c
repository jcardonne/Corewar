/*
** EPITECH PROJECT, 2022
** loop.c
** File description:
** loop
*/

#include "struct.h"
#include <unistd.h>

int get_command_duration(int id);

static void run_cmd_two(virtual_t *data, champion_t *champion, int
address, int index)
{
    if (is_cmd(data, address)) {
        COMMANDS[index - 1].instruction(data, champion);
        champion->last_used = data->cycle;
        return;
    }
    add_pc(&champion->pc, 1);
}

void run_cmds(virtual_t *data)
{
    int index;
    int duration;

    if (data->champions == NULL)
        return;
    for (int i = 0; data->champions[i] != NULL; ++i) {
        index = data->memory[get_cmd_address(data->champions[i])];
        duration = get_command_duration(index);
        if (duration == -1 || index < 1 || index > 16)
            add_pc(&data->champions[i]->pc, 1);
        else if (data->champions[i]->last_used == -1 || absolute(data->cycle -
        data->champions[i]->last_used) >= duration)
            run_cmd_two(data, data->champions[i], get_cmd_address
            (data->champions[i]), index);
    }
}
