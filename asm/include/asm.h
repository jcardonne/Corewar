/*
** EPITECH PROJECT, 2022
** asm
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_

    #include <stdio.h>

    typedef struct label_s{
        char *name;
        int *map;
        int *cmd;
        int *len_appariton;
        int cmd_len;
        int address;
        struct label_s *next;
        struct label_s *prev;
    } label_t;

    typedef struct {
        char *buffer;
        int buffer_len;
        int cmd_len;
        char *file_content;
        label_t **labels;
        FILE *fd;
    } asm_t;

    int end_with(char const *str, char *end);

    void add_char_buffer(asm_t *data, char c);
    void add_char_buffer_two(asm_t *data, char c, char c_two);

#endif /* !ASM_H_ */
