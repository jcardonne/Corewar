/*
** EPITECH PROJECT, 2022
** asm
** File description:
** data
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include "asm.h"

int init_data(asm_t *data, char *content, char const *file_name)
{
    data->buffer = NULL;
    data->buffer_len = 0;
    data->cmd_len = 0;
    data->file_content = content;
    data->labels = malloc(sizeof(label_t *));
    data->fd = fopen(file_name, "r");

    if (data->fd == NULL || data->labels == NULL || content == NULL) {
        my_put_err("[ERROR-init_data] - Can't open file / malloc failed\n");
        return 84;
    }
    return 0;
}
