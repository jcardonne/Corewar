/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** process
*/

#include "my.h"
#include "asm.h"
#include "op.h"
#include <stdlib.h>

char *my_reader(char const *av);
int init_data(asm_t *data, char *content, char const *path);
void place_len_buffer(asm_t *data);
void finds_commands_error(asm_t *data, char **args);
void parse_metadata(asm_t *data);
char **parse_commands(asm_t *data, char *buffer);
void label_place_label(asm_t *data, label_t *list);
int write_core(asm_t *data, char const *filepath);

void place_len_buffer(asm_t *data)
{
    int start = 4 + PROG_NAME_LENGTH;
    int size =
            data->buffer_len - 4 - PROG_NAME_LENGTH - 8 - COMMENT_LENGTH - 4;

    data->buffer[start + 0 + 4] = (size) >> (24);
    data->buffer[start + 1 + 4] = (size) >> (16);
    data->buffer[start + 2 + 4] = (size) >> (8);
    data->buffer[start + 3 + 4] = (size);
}

int parser(asm_t *data)
{
    char **commands = NULL;
    char *buffer = NULL;
    size_t size = 0;

    parse_metadata(data);
    while (getline(&buffer, &size, data->fd) != -1) {
        commands = parse_commands(data, buffer);
        if (!commands || !commands[0])
            continue;
        finds_commands_error(data, commands);
    }
    label_place_label(data, *data->labels);
    place_len_buffer(data);
    free(buffer);
    return 0;
}

int process_champion(char const *path)
{
    char *content = NULL;
    if (!end_with(path, ".s")) {
        my_put_err("[ERROR-process_champion] - File is not a .s file ");
        my_put_err_two(path, "\n");
        return 0;
    }
    content = my_reader(path);
    asm_t data;
    if (content == NULL) {
        my_put_err("[ERROR-process_champion] - can't read file\n");
        exit(84);
    }
    if (init_data(&data, content, path) || parser(&data) == 84 ||
        write_core(&data, path) == 84) {
        free(content);
        exit(84);
    }
    free(content);
    return (1);
}
