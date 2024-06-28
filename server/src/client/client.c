/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** client
*/

#include "server.h"

void init_client(int socketClient, sockaddr_in_t addrClient, client_t *client)
{
    client->fd = socketClient;
    client->address = addrClient;
    client->player = NULL;
    client->commands = NULL;
}

void manage_connection(server_t *server, fd_set *readfd)
{
    struct sockaddr_in addrCLient;
    int socketClient = -1;
    client_t new_client;

    if (FD_ISSET(server->sockfd, readfd)) {
        printf("waiting for connection...\n");
        socketClient = accept(server->sockfd,
        (struct sockaddr *)&addrCLient, &server->socket_size);
        if (socketClient < 0)
            print_error("Connection error");
        printf("connection accepted\n");
        dprintf(socketClient, "WELCOME\n");
        init_client(socketClient, addrCLient, &new_client);
        append_new_client(new_client, &server->clients);
    }
}

void manage_message(server_t *server, game_t *game, fd_set *readfd)
{
    linked_client_t *tmp = server->clients;
    char buffer[BUFF_SIZE];
    int valread;

    while (tmp != NULL) {
        if (FD_ISSET(tmp->client.fd, readfd)) {
            memset(buffer, 0, sizeof(buffer));
            valread = read(tmp->client.fd, &buffer, BUFF_SIZE);
            get_command(buffer, valread, &tmp->client);
        }
        tmp = tmp->next;
    }
}
