/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** linked_commands
*/

#include "command.h"

void append_new_commands(char **new_command, linked_command_t **list)
{
    linked_command_t *new_node = malloc(sizeof(linked_command_t));
    linked_command_t *last = *list;

    if (new_node == NULL)
        print_error("Malloc failed");
    new_node->command = new_command;
    new_node->next = NULL;
    if (*list == NULL) {
        *list = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

linked_command_t *pop_command(linked_command_t *node)
{
    linked_command_t *temp;

    free(node->command);
    temp = node->next;
    free(node);
    return (temp);
}

int count_commands(linked_command_t *node, int len)
{
    if (node->next != NULL)
        len = count_commands(node->next, len + 1);
    return len;
}
