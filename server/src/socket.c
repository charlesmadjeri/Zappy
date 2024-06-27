/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** socket
*/

#include "server.h"
#include <netinet/in.h>
#include <arpa/inet.h>

struct sockaddr_in generate_addr(const int port)
{
    struct sockaddr_in addr;

    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    return addr;
}

void reset_fd(server_t *server, fd_set *readfd, fd_set *writefd)
{
    linked_client_t *tmp = server->clients;

    FD_ZERO(readfd);
    FD_ZERO(writefd);
    FD_SET(server->sockfd, readfd);
    FD_SET(server->sockfd, writefd);
    while (tmp != NULL) {
        if (tmp->client.fd >= 0) {
            FD_SET(tmp->client.fd, readfd);
            FD_SET(tmp->client.fd, writefd);
        }
        tmp = tmp->next;
    }
}
