/*
** EPITECH PROJECT, 2022
** asm
** File description:
** op
*/

#ifndef _OP_H_
        #define _OP_H_

        #define COMMENT_CHAR            '#'
        #define LABEL_CHAR              ':'
        #define DIRECT_CHAR             '%'
        #define SEPARATOR_CHAR          ','
        #define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"
        #define SEPARATOR_CHARS              "\t:\n "
        #define REG_NUMBER      16

        #define NO 0
        #define REG 1
        #define DIR2 2
        #define DIR4 4
        #define IND 3
        #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

        #define PROG_NAME_LENGTH        128
        #define COMMENT_LENGTH          2048

        typedef struct valid_args_s {
                char one;
                char two;
                char three;
        } valid_args_t;

        typedef struct {
                int id;
                int duration;
                int has_op_code;
                int args_nbr;
                valid_args_t args_types[3];
            char *name;
        } cmd_t;

        static const cmd_t COMMANDS[] = {
        {1, 10, 0, 1, {{DIR4, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, "live"},
        {2, 5, 1, 2, {{DIR4, IND, NO}, {REG, NO, NO}, {NO, NO, NO}}, "ld"},
        {3, 5, 1, 2, {{REG, NO, NO}, {IND, REG, NO}, {NO, NO, NO}}, "st"},
        {4, 10, 1, 3, {{REG, NO, NO}, {REG, NO, NO}, {REG, NO, NO}}, "add"},
        {5, 10, 1, 3, {{REG, NO, NO}, {REG, NO, NO}, {REG, NO, NO}}, "sub"},
        {6, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}},
                "and"},
        {7, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}},
                "or"},
        {8, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}},
                "xor"},
        {9, 20, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, "zjmp"},
        {10, 25, 1, 3, {{REG, DIR2, IND}, {DIR2, REG, NO}, {REG, NO, NO}},
                "ldi"},
        {11, 25, 1, 3, {{REG, NO, NO}, {REG, DIR2, IND}, {DIR2, REG, NO}},
                "sti"},
        {12, 800, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, "fork"},
        {13, 10, 1, 2, {{DIR4, IND, NO}, {REG, NO, NO}, {NO, NO, NO}}, "lld"},
        {14, 50, 1, 3, {{REG, DIR2, IND}, {REG, DIR2, NO}, {REG, NO, NO}},
                "lldi"},
        {15, 1000, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}},
                "lfork"},
        {16, 2, 1, 1, {{REG, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, "aff"}
        };

        static const char MAGIC_HEADER[4] = {0, 234, 131, 243};
#endif
