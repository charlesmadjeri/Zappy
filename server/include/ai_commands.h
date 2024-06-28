/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** basic_commands
*/

#pragma once

#include "game.h"
#include "player.h"
#include "inventory.h"
#include "map.h"
#include "client.h"
#include "server.h"

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

char *right(player_t *player);
char *left(player_t *player);
char *forward(player_t *player, map_t *map);
char *inventory(inventory_t *inventory);
char *take(map_t *map, player_t *player, char *object);
char *set(map_t *map, player_t *player, char *object);
char *eject(player_t *player, server_t *server);
char *incantation(map_t *map, player_t *player, server_t *server);