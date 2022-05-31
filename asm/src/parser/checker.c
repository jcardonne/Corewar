/*
** EPITECH PROJECT, 2022
** asm
** File description:
** checker
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"

void add_address(label_t *list, char *name, int address);
void comments_railing(char *str);
int contain(const char *source, char c);
int ascii_len(char *buffer);

static void space_runner(char **buffer)
{
    for (; **buffer && **buffer != '\n' &&
        (**buffer == '\t' || **buffer == ' '); *buffer += 1);
}

static int labels_adder(asm_t *data, char **buffer)
{
    int i = 0;
    char *label_name;

    space_runner(buffer);
    if (buffer[0][i] == '.')
        return (1);
    for (; buffer[0][i] && !contain(SEPARATOR_CHARS, buffer[0][i]); ++i);
    if (buffer[0][i] != LABEL_CHAR)
        return (0);
    label_name = my_strndup(*buffer, i);
    add_address(*data->labels, label_name, data->buffer_len);
    *buffer += i + 1;
    space_runner(buffer);
    return (0);
}

static void runner(char **buffer, char **commands, int *i)
{
    int len;

    for (; *i < 4 && **buffer; *i += 1) {
        len = ascii_len(*buffer);
        commands[*i] = my_strndup(*buffer, len);
        *buffer += len;
        space_runner(buffer);
        if (**buffer == SEPARATOR_CHAR && *i == 0) {
            my_put_err("[ERROR-runner] - Wrong command format");
            exit(84);
        }
        *buffer += (**buffer == SEPARATOR_CHAR);
        space_runner(buffer);
    }
}

char **parse_commands(asm_t *data, char *buffer)
{
    char **commands;
    int i = 0;

    comments_railing(buffer);
    if (*buffer == 0 || labels_adder(data, &buffer))
        return (NULL);
    commands = malloc(sizeof(char *) * 5);
    runner(&buffer, commands, &i);
    commands[i] = NULL;
    if (*buffer != 0) {
        my_putstr("[ERROR-parse_commands] - .s format incorrect");
        exit(84);
    }
    return (commands);
}
