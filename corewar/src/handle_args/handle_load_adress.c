/*
** EPITECH PROJECT, 2022
** handle_load_adress.c
** File description:
** handle_load_adress
*/

#include "struct.h"
#include "my.h"

void handle_load_address(virtual_t *global, char *flag)
{
    if (is_digit(flag) == 1)
        global->args->load_address = my_getnbr(flag);
    else
        error_exit("[INPUT-ERROR] - Load address should contain digit only\n");
}
