/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "struct.h"

void error_handling(int ac, char **av);
void init_data(virtual_t *global, int ac, char **av);
void place_champions(virtual_t *virtual);
void loop(virtual_t *data);

int main(int ac, char **av)
{
    virtual_t virtual;

    error_handling(ac, av);
    init_data(&virtual, ac, av);
    loop(&virtual);
    return (0);
}
