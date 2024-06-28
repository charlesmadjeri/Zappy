/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** game
*/

#pragma once

#include "map.h"
#include "inventory.h"

typedef struct game_s {
    int id_count;
    int freq;
    size_t time;
    char **teams;
    int nb_teams;
    int nb_cli;
    map_t map;
    inventory_t loot;
} game_t;
