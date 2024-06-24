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
    server->socket_size = sizeof(server->addr_serv);
    if (server->sockfd < 0)
        print_error("fail to open socket.");
    printf("socket : ok\n");
    if (bind(server->sockfd, (struct sockaddr *)&server->addr_serv, server->socket_size) < 0)
        print_error("Can't bind socket.");
    printf("bind : ok\n");
    if (listen(server->sockfd, 99) < 0)
        print_error("Can't listen sockets.");
    printf("listen : ok\n");
}