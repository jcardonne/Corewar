/*
** EPITECH PROJECT, 2022
** asm
** File description:
** list
*/

#include "asm.h"

void add_node_list(label_t **list, label_t *node)
{
    node->next = NULL;
    if (*list == NULL) {
        node->prev = node;
        *list = node;
    } else {
        node->prev = (*list)->prev;
        (*list)->prev->next = node;
        (*list)->prev = node;
    }
}
