/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** free
*/

#include "server.h"

void free_clients(server_t *server)
{
    linked_client_t *tmp = server->clients;
    linked_client_t *next;

    while (tmp != NULL) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    server->clients = NULL;
}

void free_teams(game_t *game)
{
    for (int i = 0; game->teams[i] != NULL; i++)
        free(game->teams[i]);
    free(game->teams);
}

void free_memory(server_t *server, game_t *game)
{
    free_teams(game);
    free_clients(server);
}
