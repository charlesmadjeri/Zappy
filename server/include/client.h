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

/*----------MACROS----------*/

    #define BUFF_SIZE 1024

/*----------TYPEDEFS----------*/

typedef struct sockaddr_in sockaddr_in_t;

/*client_struct*/
typedef struct client_s {
    int fd;
    bool status;
    sockaddr_in_t address;
    char message[BUFF_SIZE];
    char send[BUFF_SIZE];
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
void init_client(int socketClient, sockaddr_in_t addrClient, client_t *client);

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
** @brief
**
** @param link_list
**/
void print_linked_client(linked_client_t *link_list);

/**
** @brief Get the command object
**
** @param buffer
** @param valread
** @param client
**/
void get_command(char *buffer, int valread, client_t *client);

#endif /* !CLIENT_H_ */
