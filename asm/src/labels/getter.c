/*
** EPITECH PROJECT, 2022
** asm
** File description:
** get_labels
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

void add_node_list(label_t **list, label_t *node);
int index_runner(char const *str, int i);

static int is_label(const char *str)
{
    int i = 1;

    if (str[0] != '\n')
        return 0;
    for (; str[i] != '\0' && str[i] != ':'; i++)
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            return 0;
    if (str[i] != '\0')
        return i;
    return 0;
}

static void create_dict(label_t **list, char *name)
{
    int i = 0;
    label_t *node = NULL;

    name++;
    for (; name[i] != ':'; i++);
    node = malloc(sizeof(label_t));
    node->name = malloc(sizeof(char) * (i + 1));
    my_strncpy(node->name, name, i);
    node->cmd_len = 0;
    node->map = NULL;
    node->cmd = NULL;
    node->len_appariton = NULL;
    node->address = 0;
    node->next = NULL;
    node->prev = NULL;
    add_node_list(list, node);
}

void get_all_label(label_t **list, char *str)
{
    int value;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '#')
            i = index_runner(str, i);
        value = is_label(str + i);
        if (value != 0)
            create_dict(list, str + i);
    }
}

void add_address(label_t *list, char *name, int address)
{
    while (list != NULL) {
        if (!my_strcmp(name, list->name)) {
            list->address = address;
            return;
        }
        list = list->next;
    }
    my_put_err("Missing Label declaration");
    exit(84);
}
