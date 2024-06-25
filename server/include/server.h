/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

/*----------INCLUDES----------*/
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <sys/select.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <signal.h>
    #include <time.h>
    #include "client.h"
    #include "player.h"
    #include "map.h"

/*----------MACROS----------*/

    #define MAX_CLIENTS 100

/*----------TYPEDEFS----------*/

    typedef struct game_s {
        int id_count;
        int freq;
        size_t time;
        char **teams;
        int nb_teams;
        map_t map;
        inventory_t loot;
    } game_t;

    typedef struct server_s {
        int port;
        int sockfd;
        bool status;
        struct sockaddr_in addr_serv;
        fd_set readfds;
        fd_set writefds;
        socklen_t socket_size;
        linked_lient_t *clients;
    } server_t;

    void help();

    int main_server(int ac, char **av);

    void start_server(server_t *server);

    void init_server(int ac, char **av, server_t *);

    void init_game(int ac, char **av, game_t *game);
    
    struct sockaddr_in generate_addr(const int port);

    void print_error(char *error);

    void manage_connection(server_t *server, fd_set *readfd);

#endif /* !SERVER_H_ */
