/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #define PROG_NAME_LENGTH        128
    #define COMMENT_LENGTH          2048

    typedef struct args_s {
        long dump;
        long prog_number;
        long load_address;
    } args_t;

    typedef struct {
        long id;
        long address;
        char name[PROG_NAME_LENGTH + 1];
        char comment[COMMENT_LENGTH + 1];
        char *content;
        long size;
        long *registers;
        long last_used;
        int pc;
        int cycle_of_live;
        int carry;
    } champion_t;

    typedef struct virtual_s {
        args_t *args;
        int *memory;
        champion_t **champions;
        int nb_champions;
        long cycle_dump;
        long cycle;
        int cycle_to_die;
        char *last_alive;
        long last_live_id;
        int live_calls;
    } virtual_t;

    #define MEM_SIZE                (6*1024)
    #define IDX_MOD                 512
    #define MAX_ARGS_NUMBER         4

    #define REG_NUMBER      16

    #define T_REG           1
    #define T_DIR           2
    #define T_IND           4

    #define DIR_SIZE        4

    #define NO 0
    #define REG 1
    #define DIR2 2
    #define DIR4 4
    #define IND 3

    typedef struct valid_args_s {
        char one;
        char two;
        char three;
    } valid_args_t;

    void cmd_live(virtual_t *virtual, champion_t *champion);
    void cmd_ld(virtual_t *virtual, champion_t *champion);
    void cmd_st(virtual_t *virtual, champion_t *champion);
    void cmd_add(virtual_t *virtual, champion_t *champion);
    void cmd_sub(virtual_t *virtual, champion_t *champion);
    void cmd_and(virtual_t *virtual, champion_t *champion);
    void cmd_or(virtual_t *virtual, champion_t *champion);
    void cmd_xor(virtual_t *virtual, champion_t *champion);
    void cmd_zjmp(virtual_t *virtual, champion_t *champion);
    void cmd_ldi(virtual_t *virtual, champion_t *champion);
    void cmd_sti(virtual_t *virtual, champion_t *champion);
    void cmd_fork(virtual_t *virtual, champion_t *champion);
    void cmd_lld(virtual_t *virtual, champion_t *champion);
    void cmd_lldi(virtual_t *virtual, champion_t *champion);
    void cmd_lfork(virtual_t *virtual, champion_t *champion);
    void cmd_aff(virtual_t *virtual, champion_t *champion);

    typedef struct {
        int id;
        int duration;
        int has_op_code;
        int args_nbr;
        valid_args_t args_types[3];
        char *name;
        void (*instruction)(virtual_t*, champion_t*);
    } cmd_t;

    static const cmd_t COMMANDS[] = {
        {1, 10, 0, 1, {{DIR4, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, "live",
            &cmd_live},
        {2, 5, 1, 2, {{DIR4, IND, NO}, {REG, NO, NO}, {NO, NO, NO}}, "ld",
            &cmd_ld},
        {3, 5, 1, 2, {{REG, NO, NO}, {IND, REG, NO}, {NO, NO, NO}}, "st",
            &cmd_st},
        {4, 10, 1, 3, {{REG, NO, NO}, {REG, NO, NO}, {REG, NO, NO}}, "add",
            &cmd_add},
        {5, 10, 1, 3, {{REG, NO, NO}, {REG, NO, NO}, {REG, NO, NO}}, "sub",
            &cmd_sub},
        {6, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}},
                "and", &cmd_and},
        {7, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}},
                "or", &cmd_or},
        {8, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}},
                "xor", &cmd_xor},
        {9, 20, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, "zjmp",
            &cmd_zjmp},
        {10, 25, 1, 3, {{REG, DIR2, IND}, {DIR2, REG, NO}, {REG, NO, NO}},
                "ldi", &cmd_ldi},
        {11, 25, 1, 3, {{REG, NO, NO}, {REG, DIR2, IND}, {DIR2, REG, NO}},
                "sti", &cmd_sti},
        {12, 800, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}},
            "fork", &cmd_fork},
        {13, 10, 1, 2, {{DIR4, IND, NO}, {REG, NO, NO}, {NO, NO, NO}},
            "lld", &cmd_lld},
        {14, 50, 1, 3, {{REG, DIR2, IND}, {REG, DIR2, NO}, {REG, NO, NO}},
                "lldi", &cmd_lldi},
        {15, 1000, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}},
                "lfork", &cmd_lfork},
        {16, 2, 1, 1, {{REG, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, "aff",
            &cmd_aff}
    };

    #define CYCLE_TO_DIE    1536
    #define CYCLE_DELTA     5
    #define NBR_LIVE        40

    int end_with(char *str, char *end);
    void error_exit(char *str);
    long hex_to_decimal(char *nb);
    int is_digit(const char *str);
    int absolute(long n);
    int select_address(long address);
    int place_champ(virtual_t *data, champion_t *champion, long address);
    void place_champ_n(virtual_t *data, champion_t *champion, long address);
    int get_champions_size(virtual_t *virtual);
    void add_champion(virtual_t *data, champion_t *champion);
    void remove_champion(virtual_t *data, champion_t *champion);
    champion_t *create_champion_copy(virtual_t *virtual, champion_t *champion);
    void add_pc(int *pc, int nbr);
    int get_arg_value(virtual_t *virtual, char type, long address,
                        champion_t *champion);
    int get_type_size(char type);
    int get_cmd_address(champion_t *champion);
    int is_cmd(virtual_t *virtual, long address);

    void write_new_pc(champion_t *champion, const char args[3], int
    has_ocp);
    void write_four_bytes(virtual_t *virtual, long address, int value);
    int memory_four_bytes(virtual_t *virtual, long address);
    int memory_two_byes(virtual_t *virtual, long address);
    char get_arg_type(virtual_t *virtual, long address, int arg);
    int get_arg_value_mod(virtual_t *virtual, char type, long address,
                            champion_t *champion);

#endif /* !STRUCT_H_ */
