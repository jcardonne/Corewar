/*
** EPITECH PROJECT, 2022
** asm
** File description:
** metadata_keys
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"

static int is_instruction_valid(const char *str)
{
    for (int i = 0; str[i] != '\n' && str[i]; i++)
        if (str[i] != '"' && str[i] != ' ' && str[i] != '\t')
            return (1);
    return (0);
}

void parse_name(asm_t *data, char *str, int *i)
{
    int count = 0;
    *i += 5;
    for (; (str[*i] == ' ' || str[*i] == '\t') && str[*i] != '"'
        && str[*i] != '\0'; *i += 1);
    if (str[*i] != '"') {
        my_put_err("[ERROR-parse_comment] - Incorrect .name.");
        exit(84);
    }
    *i += 1;
    for (; str[*i] != '"' && str[*i] != '\0'; ++count){
        add_char_buffer(data, str[*i]);
        *i += 1;
    }
    if (is_instruction_valid(str + *i) || count > PROG_NAME_LENGTH) {
        my_put_err("[ERROR-parse_comment] - Incorrect .name.");
        exit(84);
    }
    for (; count++ < PROG_NAME_LENGTH; add_char_buffer(data, 0));
}

void parse_comment(asm_t *head, char *str, int *i)
{
    int count = 0;
    *i += 8;
    for (; (str[*i] == ' ' || str[*i] == '\t') && str[*i] != '"'
        && str[*i] != '\0'; *i += 1);
    if (str[*i] != '"') {
        my_put_err("[ERROR-parse_metadata_comment] - Incorrect .comment.");
        exit(84);
    }
    *i += 1;
    for (; str[*i] != '"' && str[*i] != '\0'; *i += 1) {
        add_char_buffer(head, str[*i]);
        ++count;
    }
    if (is_instruction_valid(str + *i) || count > COMMENT_LENGTH) {
        my_put_err("[ERROR-parse_metadata_comment] - Incorrect .comment.");
        exit(84);
    }
    for (; count++ < COMMENT_LENGTH + 4; add_char_buffer(head, 0));
}
