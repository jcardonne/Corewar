/*
** EPITECH PROJECT, 2022
** asm
** File description:
** replacer
*/

#include "asm.h"

static void overwrite_buffer(label_t *list, asm_t *data, int pos)
{
    char *buffer = data->buffer + list->map[pos];
    int count = list->len_appariton[pos];

    if (count == 2) {
        buffer[0] = ((list->address - list->cmd[pos]) >> 8) & 255;
        buffer[1] = (list->address - list->cmd[pos]) & 255;
    } else {
        for (int i = 0; i < 4; i++)
            buffer[i] = ((list->address -
            list->cmd[pos]) >> ((3 - i) * 8)) & 255;
    }
}

void label_place_label(asm_t *data, label_t *list)
{
    while (list != NULL) {
        for (int i = 0; i < list->cmd_len; ++i)
            overwrite_buffer(list, data, i);
        list = list->next;
    }
}
