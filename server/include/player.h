/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** player
*/

#pragma once

#include "zappy.h"
#include "inventory.h"
#include "game.h"

/*----------MACROS----------*/

#define COMMANDS_MAX 10

/*----------TYPEDEFS----------*/

/*player_state*/
    typedef enum state_s {
    DEAD,
    ALIVE,
    EGG,
    NONE
} state_t;

/*player_struct*/
typedef struct player_s {
    int id;
    int direction;
    char *team_name;
    int level;
    inventory_t inventory;
    int *coords;
    state_t state;
} player_t;

void create_player(char *team_name, player_t *player, game_t *game);
