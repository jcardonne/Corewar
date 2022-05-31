/*
** EPITECH PROJECT, 2022
** loop.c
** File description:
** loop
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"

int get_command_duration(int id);

void cmd_lldi(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    char args[3] = {get_arg_type(virtual, address, 1),
                            get_arg_type(virtual, address, 2), REG};
    int value = memory_four_bytes(virtual, address +
        get_arg_value(virtual, args[0], address + 2, champion) +
        get_arg_value(virtual, args[1], address + 2 +
        get_type_size(args[0]), champion));

    champion->registers[virtual->memory[
        select_address(address + 2 + get_type_size(args[0]) +
        get_type_size(args[1]))] - 1] = value;
    champion->carry = (value == 0) ? 1 : 0;
    write_new_pc(champion, args, 1);
}

void cmd_lfork(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    long mem = get_arg_value(virtual, DIR2, address + 1, champion);
    champion_t *new = create_champion_copy(virtual, champion);

    new->address = address + champion->size + mem;
    new->pc = champion->pc + mem;
    place_champ_n(virtual, new, new->address);
    add_champion(virtual, new);
    add_pc(&champion->pc, 3);
}

static void alive_msg(virtual_t *virtual, champion_t *champion)
{
    if (my_strlen(champion->name) < 1)
        return;
    my_putstr_two(champion->name, " (");
    my_put_nbr_long(champion->id);
    my_putstr(") still alive!\n");
    if (virtual->last_alive)
        free(virtual->last_alive);
    virtual->last_alive = my_strdup(champion->name);
    virtual->last_live_id = champion->id;
}

void cmd_live(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    long mem = memory_four_bytes(virtual, address + 1);

    for (int i = 0; virtual->champions[i]; ++i) {
        if (virtual->champions[i]->id == mem)
            virtual->champions[i]->cycle_of_live = virtual->cycle;
    }
    add_pc(&champion->pc, 5);
    if (mem == champion->id)
        alive_msg(virtual, champion);
    ++virtual->live_calls;
    if (virtual->live_calls >= NBR_LIVE) {
        virtual->live_calls = 0;
        virtual->cycle_to_die -= CYCLE_DELTA;
    }
}

void cmd_aff(virtual_t *virtual, champion_t *champion)
{
    long address = get_cmd_address(champion);
    long reg = get_arg_value(virtual, REG, address + 2, champion);
    char c = reg % 256;

    my_putchar(c);
    champion->carry = (c == 0) ? 1 : 0;
    add_pc(&champion->pc, 3);
}
