/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** map
*/

#include "map.h"
#include <stdlib.h>

inventory_t init_tile()
{
    inventory_t tile;
    tile.deraumere = 0;
    tile.food = 0;
    tile.linemate = 0;
    tile.mendiane = 0;
    tile.phiras = 0;
    tile.sibur = 0;
    tile.thystame = 0;
    return tile;
}

inventory_t **init_map(int x, int y)
{
    inventory_t **map = malloc(sizeof(inventory_t **) * (x + 1));
    map[x + 1] = NULL;
    for (int row = 0; row <= x; row++) {
        map[row] = malloc(sizeof(inventory_t *) * (y));
    }
    for (int row = 0; row <= x; row++) {
        for (int col = 0; col <= y; col ++)
            map[row][col] = init_tile();
    }
    return map;
}

map_t *fill_map(map_t *map)
{
    int nb_tiles = map->x * map->y;
    int food = nb_tiles * F_DENSITY;
    int linerstate = nb_tiles * L_DENSITY;
    int deraumere = nb_tiles * D_DENSITY;
    int sibur = nb_tiles * S_DENSITY;
    int mendiane = nb_tiles * M_DENSITY;
    int phiras = nb_tiles * P_DENSITY;
    int thystame = nb_tiles * T_DENSITY;
}

map_t *create_world(int x, int y)
{
    inventory_t **map = init_map(x, y);
    return map;
}