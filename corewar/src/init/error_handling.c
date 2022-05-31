/*
** EPITECH PROJECT, 2022
** error_handling.c
** File description:
** error_handling
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int get_file_size(char *file_path);

static char *get_help_content(void)
{
    char *path = "data/help.txt";
    int size = get_file_size(path);
    int fd = open(path, O_RDONLY);
    char *string = NULL;

    if (!fd)
        error_exit("[ERROR-FILE] - Unable to open 'src/data/help.txt'\n");
    string = malloc(sizeof(char) * (size));
    for (int i = 0; i < size; ++i)
        string[i] = '\0';
    read(fd, string, size);
    close(fd);
    return (string);
}

static void show_help(int ac, char **av)
{
    char *help = NULL;

    if (ac == 2 && !my_strcmp(av[1], "-h")) {
        help = get_help_content();
        my_putstr(help);
        free(help);
        exit(0);
    }
}

static void enough_champions(int ac, char **av)
{
    int champions = 0;

    for (int i = 1; i < ac; ++i)
        if (my_strlen(av[i]) > 4 && end_with(av[i], ".cor"))
            ++champions;
    if (champions < 2)
        error_exit("[ERROR] - The VM requires at least 2 champions\n");
}

void error_handling(int ac, char **av)
{
    show_help(ac, av);
    enough_champions(ac, av);
}
