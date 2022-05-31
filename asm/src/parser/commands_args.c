/*
** EPITECH PROJECT, 2022
** asm
** File description:
** commands_args
*/

#include "op.h"

int different_char(char a, char b);

int is_indian_label(char *str)
{
    int nb = 0;

    if (str[1] == '\0')
        return (0);
    for (int i = 1; str[i] != '\0'; ++i) {
        for (int j = 0; LABEL_CHARS[j] != '\0'; ++j)
            nb += different_char(str[i], LABEL_CHARS[j]);
        if (nb == 0)
            return (0);
    }
    return (3);
}
