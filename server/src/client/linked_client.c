/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** linked_client
*/

#include "server.h"

void append_new_client(client_t client, linked_client_t **link_list)
{
    linked_client_t *new_node =
    (linked_client_t *) malloc(sizeof(linked_client_t));
    linked_client_t *last = *link_list;

    if (new_node == NULL)
        print_error("Malloc failed");
    new_node = client;
    new_node->next = NULL;
    if (*link_list == NULL) {
        *link_list = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void remove_client(linked_client_t **link_list, int fd)
{
    linked_client_t *tmp = *link_list;
    linked_client_t *prev = NULL;

    if (tmp != NULL && tmp->client.fd == fd) {
        *link_list = tmp->next;
        free(tmp);
        return; 
    }
    while (tmp != NULL && tmp->client.fd == fd) {
        prev = tmp->next;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    prev->next = tmp->next;
    free(tmp);
}

void print_linked_client(linked_client_t *link_list)
{
    while(link_list != NULL)
    {
        printf("%d : -> ", link_list->client.fd);
        link_list = link_list->next;
    }
    printf("\n");
}
