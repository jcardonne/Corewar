/*
** EPITECH PROJECT, 2022
** handle_prog_number.c
** File description:
** handle_prog_number
*/

#include "struct.h"
#include "my.h"

int is_digit(const char *str)
{
    for (int i = 0; i < str[i]; ++i)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}

void handle_prog_number(virtual_t *virtual, char *number)
{
    if (!is_digit(number))
        error_exit("[INPUT-ERROR] - Input should contain only digits\n");
    virtual->args->prog_number = my_getnbr(number);
    if (my_getnbr(number) <= 0)
        error_exit("[INPUT-ERROR] - -n must be positive.\n");
}
