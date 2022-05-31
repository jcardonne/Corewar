/*
** EPITECH PROJECT, 2022
** asm
** File description:
** write
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"

static char *get_path(char const *str)
{
    char *fp = malloc(sizeof(char) * (my_strlen(str) + 3));
    if (fp == NULL) {
        my_put_err("[ERROR-get_path] - Malloc failed\n");
        exit(84);
    }
    fp[0] = '\0';
    int i;
    int j = 0;
    for (i = my_strlen(str) - 1; str[i - 1] != '/' && i > 0; --i);
    for (; str[j] != '\0'; ++j)
        if (str[j] == '/') {
            j = -1;
            break;
        }
    if (j != - 1)
        i = 0;
    my_strcat(fp, str + i);
    fp[my_strlen(fp) - 1] = '\0';
    my_strcat(fp, "cor");
    return (fp);
}

int write_core(asm_t *data, char const *path)
{
    char *fp = get_path(path);
    int fd = open(fp, O_CREAT | O_WRONLY, 0644);

    if (fd < 0) {
        my_put_err("[ERROR-write_core] - Can't write in file\n");
        return 84;
    } else
        write(fd, data->buffer, data->buffer_len);
    close(fd);
    return 0;
}
