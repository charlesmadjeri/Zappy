/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#include "server.h"
#include <sys/socket.h>

void start_server(server_t *server)
{
    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);

    int opt = 1;

    if (server->sockfd < 0)
        print_error("Can't create socket");
    server->addr_serv = generate_addr(server->port);
    server->socket_size = sizeof(server->socket_size);
    if (setsockopt(server->sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
        print_error("setsockopt error.");
    if (bind(server->sockfd, (sockaddr_t *)&server->addr_serv, server->socket_size) < 0)
        print_error("Can't bind socket.");
    if (listen(server->sockfd, 99) < 0)
        print_error("Can't listen sockets.");
}