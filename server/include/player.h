/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** player
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "map.h"

/*----------MACROS----------*/

    #define COMMANDS_MAX 10

/*----------TYPEDEFS----------*/

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
    char *command[COMMANDS_MAX];
    inventory_t inventory;
    map_t coords;
    state_t state;
} player_t;

#endif /* !GAME_H_ */