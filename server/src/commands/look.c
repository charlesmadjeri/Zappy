/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** basic_commands
*/

#include <stdio.h>
#include "ai_commands.h"
#include <stdlib.h>

static void get_resources(char *buffer, inventory_t inventory)
{
    int offset = 0;

    if (inventory.food > 0)
        offset += sprintf(buffer + offset, "food ");
    if (inventory.linemate > 0)
        offset += sprintf(buffer + offset, "linemate ");
    if (inventory.deraumere > 0)
        offset += sprintf(buffer + offset, "deraumere ");
    if (inventory.sibur > 0)
        offset += sprintf(buffer + offset, "sibur ");
    if (inventory.mendiane > 0)
        offset += sprintf(buffer + offset, "mendiane ");
    if (inventory.phiras > 0)
        offset += sprintf(buffer + offset, "phiras ");
    if (inventory.thystame > 0)
        offset += sprintf(buffer + offset, "thystame ");
    if (offset > 0)
        buffer[offset - 1] = '\0';
}

static int get_wrapped_index(int coord, int max)
{
    if (coord < 0)
        return max - 1;
    if (coord >= max)
        return 0;
    return coord;
}

static int x_switch(map_t *map, player_t *player, int i, int l)
{
    int nx = player->coords[0];

    switch (player->direction) {
        case 0:
            nx = get_wrapped_index(player->coords[0] - l, map->x);
            break;
        case 1:
            nx = get_wrapped_index(player->coords[0] - l + i, map->x);
            break;
        case 2:
            nx = get_wrapped_index(player->coords[0] + l, map->x);
            break;
        case 3:
            nx = get_wrapped_index(player->coords[0] + l - i, map->x);
            break;
    }
    return nx;
}

static int y_switch(map_t *map, player_t *player, int i, int l)
{
    int ny = player->coords[1];

    switch (player->direction) {
        case 0:
            ny = get_wrapped_index(player->coords[1] - l + i, map->y);
            break;
        case 1:
            ny = get_wrapped_index(player->coords[1] + l, map->y);
            break;
        case 2:
            ny = get_wrapped_index(player->coords[1] + l - i, map->y);
            break;
        case 3:
            ny = get_wrapped_index(player->coords[1] - l, map->y);
            break;
    }
    return ny;
}

static char *loop(map_t *map, player_t *player, char *buffer, int l)
{
    int num_cases = l * 2 + 1;
    int nx = 0;
    int ny = 0;

    for (int i = 0; i < num_cases; i++) {
        nx = x_switch(map, player, i, l);
        ny = y_switch(map, player, i, l);
        get_resources(buffer, map->tile[player->coords[0]][player->coords[1]]);
    }
    return buffer;
}

void get_cone_view(player_t *player, map_t *map)
{
    int level = player->level;
    char buffer = malloc(sizeof(char) * 256);

    for (int l = 0; l <= level; l++) {
        buffer = loop(map, player, buffer, l);
    }
}
