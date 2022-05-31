/*
** EPITECH PROJECT, 2022
** AlbanZink
** File description:
** main
*/

#include "my.h"

int process_champion(char const *path);

int main(int const argc, char **argv)
{
    if (argc != 2 || (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')) {
        my_putstr("[USAGE] - ./asm file_name[.s]\n");
        return 0;
    }
    if (!process_champion(argv[1])) {
        my_put_err_two("[ERROR] - Assembly failed: ", argv[1]);
        my_put_err("\n");
        return 84;
    }
    my_putstr_two("[SUCCESS] - Assembly succeed: ", argv[1]);
    my_putstr("\n");
    return 0;
}
