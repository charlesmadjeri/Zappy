/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** client
*/

#pragma once

#include "zappy.h"
#include "command.h"
#include "player.h"

/*----------MACROS----------*/

    #define BUFF_SIZE_GUI 8000

/*----------TYPEDEFS----------*/

typedef struct sockaddr_in sockaddr_in_t;
typedef struct linked_command_s linked_command_t;

/*client_struct*/
typedef struct client_s {
    int fd;
    bool status;
    struct sockaddr_in address;
    char write[BUFF_SIZE_GUI];
    linked_command_t *commands;
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
void get_command(char *buffer, int valread, client_t *client, game_t *game);
