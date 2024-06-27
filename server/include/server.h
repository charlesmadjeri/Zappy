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
    #include "socket.h"
    #include "map.h"

/*----------MACROS----------*/

    #define MAX_CLIENTS 100
    #define BUFF_SIZE 1024

/*----------TYPEDEFS----------*/

typedef struct sockaddr_in sockaddr_in_t;

typedef struct game_s {
    int id_count;
    int freq;
    size_t time;
    char **teams;
    int nb_teams;
    int nb_cli;
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
    linked_client_t *clients;
} server_t;

/**
**@brief
**
**/
void help(void);

/**
**@brief
**
**@param ac
**@param av
**@return int
**/
int main_server(int ac, char **av);

void start_server(server_t *server);

/**
**@brief
**
**@param port
**@return struct sockaddr_in
**/
struct sockaddr_in generate_addr(const int port);

/**
** @brief
**
** @param server
** @param readfd
** @param writefd
**/
void reset_fd(server_t *server, fd_set *readfd, fd_set *writefd);

/**
**@brief
**
**@param ac
**@param av
**/
void init_server(int ac, char **av, server_t *);

/**
**@brief
**
**@param ac
**@param av
**@param game
**/
void init_game(int ac, char **av, game_t *game);

/**
**@brief
**
**@param error
**/
void print_error(char *error);

/**
**@brief
**
**@param server
**@param readfd
**/
void manage_connection(server_t *server, fd_set *readfd);

/**
** @brief
**
** @param server
** @param game
** @param readfd
**/
void manage_message(server_t *server, game_t *game, fd_set *readfd);

/**
** @brief
**
**/
void free_memory(server_t *server, game_t *game);

#endif /* !SERVER_H_ */
