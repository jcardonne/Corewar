/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** String -> Int
*/

int my_getnbr_two(char const * str, long n, int moins, int i)
{
    return str[i + 1] != '\0' && str[i + 1] >= 48 && str[i + 1] <= 57;
}

int my_getnbr(char const *str)
{
    long n = 0;
    int moins = 0;
    int conditions = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] == '-' ? moins++ : moins;
        if (str[i] >= 48 && str[i] <= 57) {
            n += (str[i] - 48);
            my_getnbr_two(str, n, moins, i) ? n *= 10 : n;
        } else if (str[i] != '-') {
            break;
        }
        if (str[i + 1] < 48 || str[i + 1] > 57) {
            n = moins % 2 != 0 ? (-1 * n) : n;
            n < -2147483648 || n > 2147483647 ? n = 0 : n;
            return (n);
        }
    }
    return (n);
}
