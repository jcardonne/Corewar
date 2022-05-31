/*
** EPITECH PROJECT, 2022
** asm
** File description:
** metadata
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"

void get_all_label(label_t **list, char *str);
void parse_comment(asm_t *head, char *str, int *i);
void parse_name(asm_t *data, char *str, int *i);

static int parse_properties(asm_t *data, char *str, int *i, int *name)
{
    if (str[*i] == '#')
        for (; str[*i] && str[*i] != '\n'; *i += 1);
    if (!my_strncmp(str + *i, ".name", 5)) {
        parse_name(data, str, i);
        for (int j = 0; j < 8; j++)
            add_char_buffer(data, 0);
        *name = 1;
    }
    if (*name && !my_strncmp(str + *i, ".comment", 8)) {
        parse_comment(data, str, i);
        return (1);
    }
    return (0);
}

static int parse_all_metadata(asm_t *data, char *str)
{
    int index = 0;

    for (int i = 0; str[i]; i++)
        if (parse_properties(data, str, &i, &index) == 1)
            return 0;
    my_put_err("[ERROR-parse_all_metadata] - .comment or .name is invalid.");
    exit(84);
}

void parse_metadata(asm_t *data)
{
    get_all_label(data->labels, data->file_content);
    for (int i = 0; i < 4; ++i)
        add_char_buffer(data, MAGIC_HEADER[i]);
    parse_all_metadata(data, data->file_content);
}
