/*
** EPITECH PROJECT, 2022
** asm
** File description:
** tools
*/

#include "op.h"
#include "asm.h"

void comments_railing(char *str)
{
    for (; *str && *str != '\n' && *str != COMMENT_CHAR; str += 1);
    *str = 0;
}

int ascii_len(char *buffer)
{
    int i = 0;

    for (; *buffer && *buffer != ' ' && *buffer != '\t'
            && *buffer != SEPARATOR_CHAR; ++buffer)
        ++i;
    return (i);
}

int different_char(char one, char two)
{
    return one != two ? 0 : 1;
}
