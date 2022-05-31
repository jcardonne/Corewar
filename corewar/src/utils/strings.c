/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** strings
*/

#include "my.h"

int end_with(char *str, char *end)
{
    int str_len = my_strlen(str);
    int end_len = my_strlen(end);

    if (str_len < end_len)
        return 0;

    return !my_strncmp(str + str_len - end_len, end, end_len);
}
