/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include "server.h"
    #include "player.h"

/*client_struct*/
typedef struct client_s {
    int fd;
    struct sockaddr_in address;
    char *message;
    char *send;
    player_t *player;
} client_t;

/*Linked_list_of_clients*/
typedef struct linked_client_s {
    client_t client;
    struct linked_client_s *next;
} linked_client_t;

/**
** @brief
**
** @param socketClient
** @param addrClient
** @param client
**/
void init_client(int socketClient, struct sockaddr_in addrClient,
client_t *client);

/**
** @brief
**
** @param client
** @param link_list
**/
void append_new_client(client_t client, linked_client_t **link_list);

/**
** @brief
**
** @param link_list
** @param fd
**/
void remove_client(linked_client_t **link_list, int fd);

/**
9* @brief
**
** @param link_list
**/
void print_linked_client(linked_client_t *link_list);

#endif /* !CLIENT_H_ */
