/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** socket
*/

#include "server.h"

sockaddr_in_t generate_addr(const int port)
{
    sockaddr_in_t addr;

    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_family = AF_INET;
    addr.sin_port = port == 0 ? 0 : htons(port);
    return addr;
}
