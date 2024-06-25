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
    inventory_t **map = malloc(sizeof(inventory_t *) * (x + 1));
    map[x + 1] = NULL;
    for (int row = 0; row <= x; row++) {
        map[row] = malloc(sizeof(inventory_t) * (y));
    }
    for (int row = 0; row <= x; row++) {
        for (int col = 0; col <= y; col ++)
            map[row][col] = init_tile();
    }
    return map;
}

void shuffle(int* resources, int size)
{
    if (size > 1) {
        for (int i = 0; i < size - 1; i++) {
            int j = i + rand() / (RAND_MAX / (size - i) + 1);
            int t = resources[i];
            resources[i] = resources[j];
            resources[j] = t;
        }
    }
}

map_t *fill_map(map_t *map)
{
    int nb_tiles = map->x * map->y;
    int food = nb_tiles * F_DENSITY;
    int linemate = nb_tiles * L_DENSITY;
    int deraumere = nb_tiles * D_DENSITY;
    int sibur = nb_tiles * S_DENSITY;
    int mendiane = nb_tiles * M_DENSITY;
    int phiras = nb_tiles * P_DENSITY;
    int thystame = nb_tiles * T_DENSITY;
    int total_resources = food + linemate + deraumere + sibur + mendiane + phiras + thystame;
    int *resources = malloc(sizeof(int) * total_resources);

    if (total_resources < nb_tiles)
        total_resources = nb_tiles;

    int index = 0;

    for (int i = 0; i < food; i++)
        resources[index++] = 0;
    for (int i = 0; i < linemate; i++)
        resources[index++] = 1;
    for (int i = 0; i < deraumere; i++)
        resources[index++] = 2;
    for (int i = 0; i < sibur; i++)
        resources[index++] = 3;
    for (int i = 0; i < mendiane; i++)
        resources[index++] = 4;
    for (int i = 0; i < phiras; i++)
        resources[index++] = 5;
    for (int i = 0; i < thystame; i++)
        resources[index++] = 6;
    for (; index < nb_tiles; index ++)
        resources[index] = -1;
    
    shuffle(resources, total_resources);

    index = 0;
    for (int i = 0; i < map->x; i++) {
        for (int j = 0; j < map->y; j++) {
            if (index < total_resources) {
                switch (resources[index]) {
                    case 0: map->tile[i][j].food++; break;
                    case 1: map->tile[i][j].linemate++; break;
                    case 2: map->tile[i][j].deraumere++; break;
                    case 3: map->tile[i][j].sibur++; break;
                    case 4: map->tile[i][j].mendiane++; break;
                    case 5: map->tile[i][j].phiras++; break;
                    case 6: map->tile[i][j].thystame++; break;
                }
                index++;
            }
        }
    }

    free(resources);
    return map;
}

map_t *create_world(int x, int y)
{
    inventory_t **map = init_map(x, y);
    return map;
}