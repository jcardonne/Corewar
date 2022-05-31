/*
** EPITECH PROJECT, 2021
** Strudup
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *result = malloc(sizeof(char) * (len + 1));

    for (int index = 0; src[index] != '\0'; index++)
        result[index] = src[index];
    result[len] = 0;
    return (result);
}
