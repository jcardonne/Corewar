/*
** EPITECH PROJECT, 2021
** my_char_isprintable
** File description:
** t
*/

int my_char_isprintable(char const str)
{
    int check = str >= 31 && str < 127;
    if (!check)
        return (0);
    return (1);
}
