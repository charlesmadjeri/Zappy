/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** connection
*/

#include "server.h"

void manage_connection(server_t *server, fd_set *readfd)
{
    struct sockaddr_in addrCLient;
    int socketClient = -1;
    int addrClient;
    ssize_t readval = 0;
    char buffer[8056];

    if (FD_ISSET(server->sockfd, readfd)) {
        printf("waiting for connection...\n");
        socketClient = accept(server->sockfd, (struct sockaddr *)&addrCLient,
        &server->socket_size);
        printf("connection accepted\n");
        dprintf(socketClient, "WELCOME\n");
        read(socketClient, buffer, 8057);
        if (strcmp(buffer, "GRAPHIC\n") == 0) {
            server->status = true;
        } else {
            server->status = true;
        }
    }
}