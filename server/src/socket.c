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

    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    return addr;
}
