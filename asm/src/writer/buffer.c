/*
** EPITECH PROJECT, 2022
** asm
** File description:
** buffer
*/

#include <stdlib.h>
#include "asm.h"

void add_char_buffer(asm_t *data, char c)
{
    char *str = malloc(sizeof(char) * (data->buffer_len + 1));

    str[data->buffer_len] = c;
    if (data->buffer == NULL) {
        data->buffer = str;
        ++data->buffer_len;
        return;
    }
    for (int i = 0; i < data->buffer_len; ++i)
        str[i] = data->buffer[i];
    free(data->buffer);
    data->buffer = str;
    ++data->buffer_len;
}

void add_char_buffer_two(asm_t *data, char c, char c_two)
{
    add_char_buffer(data, c);
    add_char_buffer(data, c_two);
}
