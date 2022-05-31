/*
** EPITECH PROJECT, 2022
** asm
** File description:
** commands_labels
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "op.h"

int label_runner(char *str);
int different_char(char one, char two);

static int *int_map_realloc(int *map, int old_size, int new_size)
{
    int *temp = malloc(sizeof(int) * (new_size));

    for (int i = 0; i < old_size; i++)
        temp[i] = map[i];
    if (map)
        free(map);
    return (temp);
}

static void add_label(label_t *list, char *name, const int data[3])
{
    name += label_runner(name);
    while (list) {
        if (!my_strcmp(name, list->name)) {
            list->map = int_map_realloc(list->map,
                list->cmd_len, list->cmd_len + 1);
            list->map[list->cmd_len] = data[0];
            list->cmd = int_map_realloc(list->cmd,
                list->cmd_len, list->cmd_len + 1);
            list->cmd[list->cmd_len] = data[1];
            list->len_appariton = int_map_realloc(list->len_appariton,
                list->cmd_len, list->cmd_len + 1);
            list->len_appariton[list->cmd_len] = data[2];
            ++list->cmd_len;
            return;
        }
        list = list->next;
    }
    my_put_err("[ERROR] - Missing Label declaration");
    exit(84);
}

static int add_minus_buffer_two(asm_t *data, char c, char *str)
{
    if (c != DIR2)
        return 0;
    add_label(*data->labels, str, (int [3]){data->buffer_len,
                    data->cmd_len, 2});
    add_char_buffer(data, 0);
    add_char_buffer(data, 0);
    return 1;
}

int add_minus_buffer(asm_t *data, char c, char *str)
{
    int label = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        label += (str[i] == ':');
    if (label == 0)
        return 0;
    if (c != DIR4)
        return add_minus_buffer_two(data, c, str);
    add_label(*data->labels, str, (int [3]){data->buffer_len,
            data->cmd_len, 4});
    add_char_buffer(data, 0);
    add_char_buffer(data, 0);
    add_char_buffer(data, 0);
    add_char_buffer(data, 0);
    return 1;
}

int print_label_indian(asm_t *data, char c, char *str)
{
    int label = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        label += str[i] == ':';
    if (label == 0 || c != IND)
        return 0;
    add_label(*data->labels, str, (int [3]){data->buffer_len,
            data->cmd_len, 2});
    add_char_buffer(data, 0);
    add_char_buffer(data, 0);
    return 1;
}
