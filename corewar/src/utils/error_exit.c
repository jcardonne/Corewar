/*
** EPITECH PROJECT, 2022
** error_exit.c
** File description:
** error_exit
*/

#include "my.h"
#include <stdlib.h>

void error_exit(char *str)
{
    my_put_err(str);
    exit(84);
}
