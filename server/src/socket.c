/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** socket
*/

#include "server.h"
#include <netinet/in.h>
#include <arpa/inet.h>

sockaddr_in_t generate_addr(const int port)
{
    sockaddr_in_t addr;

    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1024);
    return addr;
}
