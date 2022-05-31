/*
** EPITECH PROJECT, 2022
** asm
** File description:
** get_pos
*/

#include "op.h"
#include "my.h"

static int go_to_label_two(const char *str, int i)
{
    for (int j = 0; j < my_strlen(LABEL_CHARS); ++j)
        if (str[i] == LABEL_CHARS[j])
            return i;
    return -1;
}

int label_runner(char *str)
{
    int result;

    for (int i = 0; i < my_strlen(str); ++i) {
        result = go_to_label_two(str, i);
        if (result != -1)
            return result;
    }
    return 0;
}

int index_runner(const char *str, int i)
{
    for (; str[i] && str[i] != '\n'; i++);
    return i;
}
