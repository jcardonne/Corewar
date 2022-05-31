/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** parser
*/

#include "struct.h"
#include <stdlib.h>

static void header_reader(const char *content, champion_t *champion)
{
    for (int i = 4; i < 4 + PROG_NAME_LENGTH; ++i)
        champion->name[i - 4] = content[i];
    champion->name[PROG_NAME_LENGTH] = '\0';
    for (int i = 12 + PROG_NAME_LENGTH; i < 12 + PROG_NAME_LENGTH +
                                            COMMENT_LENGTH; ++i)
        champion->comment[i - 12 - PROG_NAME_LENGTH] = content[i];
    champion->comment[COMMENT_LENGTH] = '\0';
    champion->size = content[4 + PROG_NAME_LENGTH];
    for (int i = 5 + PROG_NAME_LENGTH; i < 12 + PROG_NAME_LENGTH; ++i) {
        champion->size = champion->size << 8;
        champion->size += content[i];
    }
}

static void is_load_addy_valid(virtual_t *global, champion_t *champion)
{
    if (champion->address != -1 && !place_champ(global, champion,
                                                champion->address))
        error_exit("[ERROR] - LOAD ADDRESS IS INVALID FOR A CHAMPION\n");
}

static void content_setter(const char *content, champion_t *new)
{
    new->content = malloc(sizeof(char) * new->size);

    if (new->content == NULL)
        error_exit("[ERROR-content_setter] - MALLOC FAILED\n");
    for (int i = 12 + PROG_NAME_LENGTH + COMMENT_LENGTH; i < 12 +
        PROG_NAME_LENGTH + COMMENT_LENGTH + new->size; ++i)
        new->content[i - 12 - PROG_NAME_LENGTH - COMMENT_LENGTH] =
            content[i + 4];
}

void cor_parser(virtual_t *data, char *content)
{
    champion_t *champ = malloc(sizeof(champion_t));
    ++data->nb_champions;
    champ->id = data->args->prog_number == -1 ? data->nb_champions :
                                                data->args->prog_number;
    champ->address = !data->args->load_address ? -1 : data->args->load_address;
    champ->carry = 0;
    champ->cycle_of_live = 0;
    champ->pc = 0;
    champ->size = 0;
    header_reader(content, champ);
    content_setter(content, champ);
    champ->registers = malloc(sizeof(long) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; ++i)
        champ->registers[i] = 0;
    champ->registers[0] = champ->id;
    champ->last_used = -1;
    is_load_addy_valid(data, champ);
    add_champion(data, champ);
}
