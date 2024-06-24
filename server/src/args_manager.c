/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** args_manager
*/

#include "../include/server.h"

int get_port(int ac, char **av)
{
    int port = 1024;
    int i = 0;

    for (; i != ac; i++)
        if (strcmp(av[i], "-p") == 0)
            break;
    if (i == ac) {
        return port;  
    } else if (i >= ac || atoi(av[i+1]) <= 0) {
        print_error("Incorrect port given");
    port = atoi(av[i+1]);
    }
    return (port);
}

void init_server(int ac, char **av, server_t *server)
{
    server->port = get_port(ac, av);
    printf("port : %d\n", server->port);
    server->clients = NULL;
    server->socket_size = sizeof(struct sockaddr_in);
    server->client = NULL;
    server->status = false;
}