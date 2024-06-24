/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include "server.h"
    
    /*client_struct*/
    typedef struct client_s {
        int fd;
        struct sockaddr_in address;
        player_t *player;
    } client_t;

    /*Linked_list_of_clients*/
    typedef struct linked_client_s {
        client_t client;
        struct linked_client_s *next;
    } linked_lient_t;


#endif /* !CLIENT_H_ */
