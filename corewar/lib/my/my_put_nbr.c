/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Put NBR
*/

#include "my.h"
#include <unistd.h>

int my_put_nbr(int nb)
{
    int temp;

    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return (0);
    }
    if (nb < 0) {
        my_putchar(45);
        nb *= -1;
    }
    if (nb >= 10) {
        temp = (nb % 10);
        nb = (nb - temp) / 10;
        my_put_nbr(nb);
        my_putchar(temp + '0');
    } else
        my_putchar(nb % 10 + '0');
    return (0);
}

int my_put_nbr_long(long nb)
{
    long temp;
    long max = -9223372036854775807;

    if (nb == max) {
        write(1, "-9223372036854775807", 20);
        return (0);
    }
    if (nb < 0) {
        my_putchar(45);
        nb *= -1;
    }
    if (nb >= 10) {
        temp = (nb % 10);
        nb = (nb - temp) / 10;
        my_put_nbr_long(nb);
        my_putchar(temp + '0');
    } else
        my_putchar(nb % 10 + '0');
    return (0);
}
