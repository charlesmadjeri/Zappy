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
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>

    typedef struct sockaddr_in sockaddr_in_t;
    typedef struct sockaddr sockaddr_t;

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
        bool status;
        sockaddr_in_t addr_serv;
        socklen_t socket_size;
        client_t *sever_client;
        linked_lient_t *clients;
    } server_t;

    int main_server(int ac, char **av);

    /**
     * @brief Called to start main loop 
     * 
     * @param server structure containing server's information
     */
    void start_server(server_t *server);

    void init_serv(int ac, char **av, server_t *);
   sockaddr_in_t generate_addr(const int port);

    void print_error(char *error);

    void init_net(int ac, char **av, server_t *serv);
#endif /* !SERVER_H_ */
