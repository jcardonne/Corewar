/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** Copy string
*/

char *my_strcpy(char *dest , char const *src)
{
    for (int i = 0; i < *src != '\0'; i++) {
        *dest++ = *src++;
    }
    return dest;
}
