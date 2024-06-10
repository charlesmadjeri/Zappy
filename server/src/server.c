/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#include "server.h"

void start_server(server_t server)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (fd < 0)
        print_error("Can't create socket");
}
