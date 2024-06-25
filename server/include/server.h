/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <sys/select.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>

    #include "client.h"
    #include "game.h"

    #define MAX_CLIENTS 100

    typedef struct server_s {
        int port;
        int sockfd;
        bool status;
        struct sockaddr_in addr_serv;
        fdset readfds;
        fdset writefds;
        socklen_t socket_size;
        client_t *client;
        linked_lient_t *clients;
    } server_t;

    int main_server(int ac, char **av);

    void start_server(server_t *server);

    void init_server(int ac, char **av, server_t *);
    
    struct sockaddr_in generate_addr(const int port);

    void print_error(char *error);

    void manage_connection(server_t *server, fd_set *readfd);

#endif /* !SERVER_H_ */
