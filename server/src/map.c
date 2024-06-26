/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** map
*/

#include "map.h"
#include <stdlib.h>
#include <time.h>

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

    map[x] = NULL;
    for (int row = 0; row < x; row++) {
        map[row] = malloc(sizeof(inventory_t) * (y));
    }
    for (int row = 0; row < x; row++) {
        for (int col = 0; col < y; col ++)
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

static resource_t init_resource(int nb_tiles)
{
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
    return resource;
}

static map_t *fill_excess(map_t *map, int *resource_list,
    int nb_tiles, int size)
{
    int *new_resource_list = resource_list;

    if (size < nb_tiles) {
        new_resource_list = malloc(sizeof(int) * nb_tiles);
        for (int i = 0; i < nb_tiles; i++) {
            new_resource_list[i] = -1;
        }
        for (int i = 0; i < size; i++) {
            new_resource_list[i] = resource_list[i];
        }
        resource_list = new_resource_list;
    }
    shuffle(new_resource_list, nb_tiles);
    map = fill_tiles(map, new_resource_list, nb_tiles);
    if (size > nb_tiles)
        fill_excess(map, &new_resource_list[nb_tiles], nb_tiles,
            size - nb_tiles);
    free(new_resource_list);
    return map;
}

map_t fill_map(map_t *map)
{
    int nb_tiles = map->x * map->y;
    int *resources_list = {0};
    resource_t resource = init_resource(nb_tiles);

    resources_list = init_resource_list(&resource, nb_tiles);
    shuffle(resources_list, resource.total_resources);
    map = fill_tiles(map, resources_list, resource.total_resources);
    if (resource.total_resources > nb_tiles) {
        printf("i:%i\t%i\n", nb_tiles, resource.total_resources);
        fill_excess(map, &resources_list[nb_tiles], nb_tiles,
            resource.total_resources - nb_tiles);
    }
    free(resources_list);
    return *map;
}

map_t create_world(int x, int y)
{
    map_t map;

    map.x = x;
    map.y = y;
    map.tile = init_map(x, y);
    map = fill_map(&map);
    return map;
}
