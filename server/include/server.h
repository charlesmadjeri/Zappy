/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#pragma once

#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct sockaddr_in sockaddr_in_t;

/*typedef enum ressource_s {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
} ressource_t;*/

/*player_inventory*/
typedef struct inventory_s {
    int food;
    int linerstate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} inventory_t;

/*player_coordonates*/
typedef struct coords_s {
    int x;
    int y;
} coords_t;

/*player_state*/
typedef enum state_s {
    DEAD,
    ALIVE,
    EGG
} state_t;

/*player_struct*/
typedef struct player_s {
    int id;
    char *team_name;
    int level;
    inventory_t inventory;
    coords_t coords;
    state_t state;
} player_t;

/*client_struct*/
typedef struct client_s {
    int fd;
    sockaddr_in_t address;
    player_t *player;
} client_t;

/*Linked_list_of_clients*/
typedef struct linked_client_s {
    client_t client;
    struct linked_client_s *next;
} linked_lient_t;

typedef struct server_s {
    int port;
    int sockfd;
    sockaddr_in_t addr_serv;
    socklen_t socket_size;
    client_t *sever_client;
    linked_lient_t clients;
} server_t;

int main_loop () {}

int manage_client_connection() {}

void print_error(char *error);