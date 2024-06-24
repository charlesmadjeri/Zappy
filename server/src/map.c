/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** map
*/

#include "game.h"
#include <stdlib.h>

inventory_t init_tile()
{
    inventory_t tile;
    tile.deraumere = 0;
    tile.food = 0;
    tile.linerstate = 0;
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
        map[row] = malloc(sizeof(inventory_t *) * (y + 1));
        map[row][y + 1] = NULL;
    }
    for (int row = 0; row <= x; row++) {
        for (int col = 0; col <= y; col ++)
            map[row][col] = init_tile();
    }
    return map;
}

inventory_t **create_world(int x, int y)
{
    inventory_t **map = init_map(x, y);
    return map;
}