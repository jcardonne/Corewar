/*
** EPITECH PROJECT, 2022
** init_data.c
** File description:
** init_data
*/

#include "struct.h"
#include "my.h"

#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>

void handle_prog_number(virtual_t *virtual, char *number);
void handle_load_address(virtual_t *virtual, char *flag);
void cor_parser(virtual_t *data, char *file);
void place_champions(virtual_t *virtual);
void init_data_two(virtual_t *virtual);

int get_file_size(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char content;
    int size = 0;

    if (fd < 0)
        error_exit("[ERR0R] - FILE CAN'T OPEN\n");
    for (; read(fd, &content, 1); ++size);
    return (size);
}

void read_file(char *path, char **buffer)
{
    int size = get_file_size(path);
    int fd = open(path, O_RDONLY);
    char *content = malloc(sizeof(char) * (size + 1));

    if (content == NULL)
        error_exit("[ERROR-read_file] - MALLOC FAILED\n");
    content[size] = '\0';
    if (read(fd, content, size) != size)
        error_exit("[ERROR] - FILE CAN'T READ\n");
    if (!(content[0] == 0 && content[1] == -22 && content[2] == -125
    && content[3] == -13))
        error_exit("[ERROR] - FILE INCORRECT\n");
    *buffer = content;
}

static void handle_file(virtual_t *data, char *path)
{
    char *buffer = NULL;

    read_file(path, &buffer);
    cor_parser(data, buffer);
    data->args->prog_number = -1;
    data->args->load_address = 0;
    free(buffer);
}

static void handle_flags(virtual_t *virtual, int i, int ac, char **av)
{
    if (ac <= i + 1)
        error_exit("[ERROR] - value of -n is invalid\n");
    if (!my_strcmp(av[i], "-a"))
        handle_load_address(virtual, av[i + 1]);
    if (!my_strcmp(av[i], "-dump"))
        virtual->args->dump = hex_to_decimal(av[i + 1]);
    if (!my_strcmp(av[i], "-n"))
        handle_prog_number(virtual, av[i + 1]);
}

void init_data(virtual_t *virtual, int ac, char **av)
{
    init_data_two(virtual);
    if (virtual->args == NULL || virtual->memory == NULL)
        error_exit("[ERROR-init_data] - malloc failed\n");
    for (int i = 0; i < MEM_SIZE; ++i)
        virtual->memory[i] = 0;
    for (int i = 1; i < ac; ++i) {
        if (av[i][0] == '-')
            handle_flags(virtual, i++, ac, av);
        else
            handle_file(virtual, av[i]);
    }
    if (get_champions_size(virtual) < 2)
        error_exit("[ERROR] - Minimum champions must be valid to start\n");
    place_champions(virtual);
}
