/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#include "args.h"
#include "server.h"
#include <sys/socket.h>

void init_server(int ac, char **av, server_t *server)
{
    server->port = get_port(ac, av);
    printf("port : %d\n", server->port);
    server->clients = NULL;
    server->socket_size = sizeof(struct sockaddr_in);
    server->status = false;
}

void start_server(server_t *server)
{
    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sockfd < 0)
        print_error("Can't create socket");
    printf("socket : ok\n");
    server->addr_serv = generate_addr(server->port);
    server->socket_size = sizeof(server->addr_serv);
    if (bind(server->sockfd, (struct sockaddr *)&server->addr_serv,
    server->socket_size) < 0)
        print_error("Can't bind socket.");
    printf("bind : ok\n");
    if (listen(server->sockfd, 99) < 0)
        print_error("Can't listen sockets.");
    printf("listen : ok\n");
}
