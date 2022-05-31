/*
** EPITECH PROJECT, 2021
** my_grep
** File description:
** my_grep
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include "my.h"

static char *my_error(char *str)
{
    if (str != NULL)
        free(str);
    return ("-84");
}

static char *my_malloc(size_t size)
{
    char *buf = malloc(size);

    if (buf != NULL)
        return buf;
    my_put_err("ERROR DURING MALLOC BUF\n");
    return (NULL);
}

static char *my_cat_two(char const *input)
{
    int fd;
    long ret;
    off_t size = 2000000;
    char *buf = my_malloc(sizeof(char) * (size + 1));

    if (buf == NULL)
        return ("-84");
    if (size == -1)
        return (my_error(buf));
    fd = open(input, O_RDONLY);
    if (fd == -1)
        return (my_error(buf));
    do {
        ret = read(fd, buf, size);
    } while (ret != 0);
    if (close(fd) == -1)
        return (my_error(buf));
    buf[size] = '\0';
    return (buf);
}

char *my_reader(char const *av)
{
    char *result = my_cat_two(av);

    if (!my_strcmp(result, "-84"))
        return (NULL);
    return (result);
}
