/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#include "server.h"

void start_server(server_t *server)
{
    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;

    if (server->sockfd < 0)
        print_error("Can't create socket");
}
