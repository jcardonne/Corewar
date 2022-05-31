/*
** EPITECH PROJECT, 2022
** asm
** File description:
** commands
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"

void write_args_buffer(asm_t *data, char **args, int i, char argv[]);
void add_address(label_t *list, char *name, int address);
void comments_railing(char *str);

int is_indian_label(char *str);
int is_char_valid(char *str);

static int is_reg(char *str)
{
    if (str[0] != 'r' || str[1] == '\0')
        return (0);
    for (int i = 1; str[i] != '\0'; i += 1)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    int value = my_getnbr(str + 1);
    return value == 0 || value > REG_NUMBER ? 0 : 1;
}

static int is_indian(char *str)
{
    int i = 0;

    if (str[0] == '\0') {
        my_put_err("[ERROR-is_indian] - Zero in first character of arg\n");
        exit(84);
    }
    if (str[0] == LABEL_CHAR)
        return (is_indian_label(str));
    if (str[0] == '-' && str[1] != '\0')
        ++i;
    for (; str[i] != '\0'; ++i)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    long value = my_getlongnbr(str);
    if (value > 65536 || value < -65536) {
        my_put_err("[ERROR-is_indian] - indirect value too high\n");
        exit(84);
    }
    return (3);
}

static int is_dir(char *str, int type)
{
    int i = 1;

    if (str[1] == '\0')
        return (0);
    if (str[1] == '-' && str[2] != '\0')
        ++i;
    if (str[1] == '-' && str[2] == '\0')
        return (0);
    for (; str[i] != '\0'; ++i)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    long value = my_getlongnbr(str + 1);
    if ((type == DIR4 && (value > 4294967296 || value < -4294967296)) ||
        (type == DIR2 && (value > 65535 || value < - 65535))) {
        my_put_err("[ERROR-is_dir] - DIR Value too high\n");
        exit(84);
    }
    return (2);
}

static int is_arg(int t, char *arg)
{
    int value = 0;

    if (!arg[0]) {
        my_put_err("[Error-is_arg] - null at first char\n");
        exit(84);
    }
    if (t == NO)
        return 0;
    if (t == DIR4 || t == DIR2) {
        if (arg[0] != DIRECT_CHAR)
            return 0;
        value = (arg[1] == ':') ? is_char_valid(arg) : is_dir(arg, t);
        value = (t == DIR4 && value != 0) ? value + 2 : value;
    }
    if (t == IND)
        value = is_indian(arg);
    else if (t == REG)
        value = is_reg(arg);
    return (value);
}

void args_parser(asm_t *data, char **args, int i)
{
    int arg_counter = COMMANDS[i].args_nbr;
    int j = 1;
    char argv[] = {0, 0, 0};

    for (; args[j] != NULL; ++j);
    if (j - 1 != arg_counter) {
        my_put_err("[ERROR-args_parser] - Invalid number of args\n");
        exit(84);
    }
    for (int x = 0; x < arg_counter; ++x) {
        argv[x] += is_arg(COMMANDS[i].args_types[x].one, args[x + 1]);
        argv[x] += is_arg(COMMANDS[i].args_types[x].two, args[x + 1]);
        argv[x] += is_arg(COMMANDS[i].args_types[x].three, args[x + 1]);
    }
    for (j = 0; j < arg_counter; ++j)
        if (argv[j] == 0) {
            my_put_err("[ERROR-args_parser] - invalid chars arguments");
            exit(84);
        }
    write_args_buffer(data, args, i, argv);
}
