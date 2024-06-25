/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** player
*/

#ifndef GAME_H_
    #define GAME_H_

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


#endif /* !GAME_H_ */
