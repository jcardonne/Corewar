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

    if (src == NULL)
        return (NULL);
    for (int index = 0; index < len; index++)
        result[index] = src[index];
    result[len] = '\0';
    return (result);
}

char *my_strndup(char *str, int len)
{
    char *result = NULL;

    if (str == NULL)
        return (NULL);
    result = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
        result[i] = str[i];
    result[len] = '\0';
    return (result);
}
