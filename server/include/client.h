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

typedef struct sockaddr_in sockaddr_in_t;

/*client_struct*/
typedef struct client_s {
    int fd;
    struct sockaddr_in address;
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
9* @brief
**
** @param link_list
**/
void print_linked_client(linked_client_t *link_list);
