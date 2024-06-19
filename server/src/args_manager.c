/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** args_manager
*/

#include "../include/server.h"

int get_port(int ac, char **av)
{
    int port = 4444;
    int i = 0;

    for (; i != ac; i++)
        if (strcmp(av[i], "-p") == 0)
            break;
    if (i == ac)
        return port;
    else
        print_error("Incorrect port given");
    return (0);
}

void init_net(int ac, char **av, server_t *serv)
{
    serv->port = get_port(ac, av);
    serv->clients = NULL;
    serv->socket_size = sizeof(struct sockaddr_in);
    serv->sever_client = NULL;
}