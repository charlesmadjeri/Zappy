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
    if (i == ac)
        return port;
    else if(i >= ac || atoi(av[i+1]) <= 0)
        print_error("Incorrect port given");
    port = atoi(av[i+1]);
    return (port);
}

void init_serv(int ac, char **av, server_t *serv)
{
    serv->port = get_port(ac, av);
    serv->clients = NULL;
    serv->socket_size = sizeof(struct sockaddr_in);
    serv->sever_client = NULL;
    serv->status = false;
}