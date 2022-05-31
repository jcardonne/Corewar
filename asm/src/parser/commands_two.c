/*
** EPITECH PROJECT, 2022
** asm
** File description:
** commands_two
*/

#include "my.h"
#include "asm.h"
#include "op.h"

void print_one_args(asm_t *data, char c, char *str);
int add_minus_buffer(asm_t *data, char c, char *str);
void args_parser(asm_t *data, char **args, int i);
int print_label_indian(asm_t *data, char c, char *str);

static int finds_opc_value(char c, int one, int two)
{
    if (c == REG)
        return (two);
    if (c == DIR4 || c == DIR2)
        return (one);
    if (c == IND)
        return (one + two);
    return (0);
}

void write_args_buffer(asm_t *data, char **args, int i, char argv[])
{
    int op_code = 0;

    if (COMMANDS[i].has_op_code) {
        op_code += finds_opc_value(argv[0], 128, 64);
        op_code += finds_opc_value(argv[1], 32, 16);
        op_code += finds_opc_value(argv[2], 8, 4);
        add_char_buffer(data, op_code);
    }
    print_one_args(data, argv[0], args[1]);
    print_one_args(data, argv[1], args[2]);
    print_one_args(data, argv[2], args[3]);
}

int finds_commands_error(asm_t *data, char **args)
{
    int i = 0;

    if (!args[0]) {
        my_put_err("[ERROR-finds_commands_error] - Line invalid\n");
        return 84;
    }
    data->cmd_len = data->buffer_len;
    for (; i < 16; ++i)
        if (!my_strcmp(args[0], COMMANDS[i].name)) {
            add_char_buffer(data, COMMANDS[i].id);
            args_parser(data, args, i);
            i = -1;
            break;
        }
    if (i != -1) {
        my_put_err("[ERROR-command_err] - Invalid Command Name (not found)\n");
        return 84;
    }
    return 0;
}

static void print_one_args_aux(asm_t *data, char c, char *str, long nb)
{
    if (c == DIR2 && !add_minus_buffer(data, c, str)) {
        if (my_getlongnbr(str + 1) < 0) {
            nb = 65536 + my_getlongnbr(str + 1);
            add_char_buffer(data, nb / 256);
            add_char_buffer(data, nb % 256);
        } else {
            add_char_buffer(data, my_getlongnbr(str + 1) / 256);
            add_char_buffer(data, my_getlongnbr(str + 1) % 256);
        }
    }
    if (c == IND && !print_label_indian(data, c, str)) {
        if (my_getlongnbr(str) < 0) {
            nb = 65536 + my_getlongnbr(str);
            add_char_buffer(data, nb / 256);
            add_char_buffer(data, nb % 256);
        } else {
            add_char_buffer(data, my_getlongnbr(str) / 256);
            add_char_buffer(data, my_getlongnbr(str) % 256);
        }
    }
}

void print_one_args(asm_t *data, char c, char *str)
{
    long nb = 0;

    if (c == 0)
        return;
    if (c == REG)
        add_char_buffer(data, my_getlongnbr(str + 1));
    if (c == DIR4 && !add_minus_buffer(data, c, str)) {
        if (my_getlongnbr(str + 1) < 0) {
            nb = 4294967296 + my_getlongnbr(str + 1);
            add_char_buffer_two(data, nb / 16777216, nb / 65536);
            add_char_buffer_two(data, nb / 256, nb % 256);
        } else {
            add_char_buffer_two(data, my_getlongnbr(str + 1) / 16777216,
                my_getlongnbr(str + 1) / 65536);
            add_char_buffer_two(data, my_getlongnbr(str + 1) / 256,
                my_getlongnbr(str + 1) % 256);
        }
    }
    print_one_args_aux(data, c, str, nb);
}
