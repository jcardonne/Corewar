/*
** EPITECH PROJECT, 2022
** asm
** File description:
** commands_three
*/

#include "op.h"

int different_char(char one, char two);

int is_char_valid(char *str)
{
    int nb = 0;

    for (int i = 2; str[i] != '\0'; ++i) {
        for (int j = 0; LABEL_CHARS[j] != '\0'; ++j)
            nb += different_char(str[i], LABEL_CHARS[j]);
        if (nb == 0)
            return (0);
        nb = 0;
    }
    return (2);
}
