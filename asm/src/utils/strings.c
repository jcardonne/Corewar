/*
** EPITECH PROJECT, 2022
** asm
** File description:
** strings
*/

#include "my.h"
#include <stdlib.h>

int end_with(char const *str, char *end)
{
    int str_len = my_strlen(str);
    int end_len = my_strlen(end);

    if (str_len < end_len)
        return 0;

    return !my_strncmp(str + str_len - end_len, end, end_len);
}

int contain(const char *source, char c)
{
    for (int i = 0; source[i]; i++)
        if (source[i] == c)
            return 1;
    return 0;
}
