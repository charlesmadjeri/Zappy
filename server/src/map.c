/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** map
*/

#include "map.h"
#include "resources.h"
#include <stdlib.h>

static inventory_t init_tile(void)
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

static inventory_t **init_map(int x, int y)
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

static void shuffle(int *resources_list, int size)
{
    int j = 0;
    int t = 0;

    srand(time(NULL));
    if (size > 1) {
        for (int i = 0; i < size - 1; i++) {
            j = i + rand() / (RAND_MAX / (size - i) + 1);
            t = resources_list[i];
            resources_list[i] = resources_list[j];
            resources_list[j] = t;
        }
    }
}

static map_t *end_loop_statement(map_t *map, int current_ressource,
    int i, int j)
{
    switch (current_ressource) {
        case 4:
            map->tile[i][j].mendiane++;
            break;
        case 5:
            map->tile[i][j].phiras++;
            break;
        case 6:
            map->tile[i][j].thystame++;
            break;
        default:
            break;
    }
    return map;
}

static map_t *loop_statement(map_t *map, int current_ressource, int i, int j)
{
    switch (current_ressource) {
        case 0:
            map->tile[i][j].food++;
            break;
        case 1:
            map->tile[i][j].linemate++;
            break;
        case 2:
            map->tile[i][j].deraumere++;
            break;
        case 3:
            map->tile[i][j].sibur++;
            break;
        default:
            map = end_loop_statement(map, current_ressource, i, j);
    }
}

static map_t *fill_tiles(map_t *map, int *resources_list, int nb_tiles)
{
    int index = 0;

    for (int i = 0; i < map->x; i++) {
        if (index >= nb_tiles)
            break;
        for (int j = 0; j < map->y; j++) {
            loop_statement(map, resources_list[index], i, j);
            index++;
        }
    }
    return map;
}

map_t *fill_map(map_t *map)
{
    int nb_tiles = map->x * map->y;
    int *resources_list = {0};
    resource_t resource;

    resource.food = nb_tiles * F_DENSITY;
    resource.linemate = nb_tiles * L_DENSITY;
    resource.deraumere = nb_tiles * D_DENSITY;
    resource.sibur = nb_tiles * S_DENSITY;
    resource.mendiane = nb_tiles * M_DENSITY;
    resource.phiras = nb_tiles * P_DENSITY;
    resource.thystame = nb_tiles * T_DENSITY;
    resource.total_resources = resource.food + resource.linemate +
        resource.deraumere + resource.sibur +
        resource.mendiane + resource.phiras + resource.thystame;
    resources_list = init_resource_list(&resource, nb_tiles);
    shuffle(resources_list, resource.total_resources);
    map = fill_tiles(map, resources_list, resource.total_resources);
    free(resources_list);
    return map;
}

map_t *create_world(int x, int y)
{
    map_t *map = malloc(sizeof(map_t));

    map->tile = init_map(x, y);
    map = fill_map(map);
    return map;
}
