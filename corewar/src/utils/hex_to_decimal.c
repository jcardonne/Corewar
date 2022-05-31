/*
** EPITECH PROJECT, 2022
** hex_to_decimal.c
** File description:
** hex_to_decimal
*/

#include "my.h"

static long to_power(long x, int pow)
{
    int result = 1;

    for (; pow > 0; --pow)
        result *= x;
    return (result);
}

long hex_to_decimal(char *nb)
{
    long result = 0;
    int power = 0;
    int end = nb[0] == '-' ? 1 : 0;

    if (my_strcmp(nb, "0") == 0)
        return (0);
    for (int i = my_strlen(nb); i != end; i--) {
        if (nb[i - 1] >= 'A' && nb[i - 1] <= 'F')
            result += (nb[i - 1] - 55) * to_power(16, power);
        else
            result += (nb[i - 1] - '0') * to_power(16, power);
        power++;
    }
    return (nb[0] == '-' ? -1 * result : result);
}
