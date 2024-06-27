/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** client
*/

#include "server.h"

void init_client(int socketClient, struct sockaddr_in addrClient,
client_t *client)
{
    client->fd = socketClient;
    client->address = addrClient;
    client->message = NULL;
    client->send = NULL;
    client->player = NULL;
}

void manage_connection(server_t *server, fd_set *readfd)
{
    struct sockaddr_in addrCLient;
    int socketClient = -1;
    client_t new_client;

    if (FD_ISSET(server->sockfd, readfd)) {
        printf("waiting for connection...\n");
        socketClient = accept(server->sockfd,
        (const struct sockaddr *)&addrCLient, &server->socket_size);
        if (socketClient < 0)
            print_error("Connection error");
        printf("connection accepted\n");
        dprintf(socketClient, "WELCOME\n");
        init_client(socketClient, addrCLient, &new_client);
        append_new_client(new_client, &server->clients);
    }
}
void manage_message(server_t *server, game_t *game)
{
    char buffer[8056];
}
