/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** basic_commands
*/

#include "ai_commands.h"

char *right(player_t *player)
{
    player->direction = (player->direction + 1) % 4;
    return "ok";
}

char *left(player_t *player)
{
    player->direction = (player->direction - 1) % 4;
    return "ok";
}

static int *get_wrapped_index(int *coord, int x, int y)
{
    if (coord[0] < 0)
        return x - 1;
    if (coord[0] >= x)
        return 0;
    if (coord[1] < 0)
        return y - 1;
    if (coord[1] >= y)
        return 0;
    return coord;
}

char *forward(player_t *player, map_t *map)
{
    switch (player->direction) {
        case RIGHT:
            player->coords[0] ++;
            break;
        case LEFT:
            player->coords[0] --;
            break;
        case UP:
            player->coords[1] --;
            break;
        case DOWN:
            player->coords[1] ++;
            break;
        default:
            return "ko";
    }
    player->coords = get_wrapped_index(player->coords, map->x, map->y);
    return "ok";
}

char *inventory(inventory_t *inventory)
{
    int size = snprintf(NULL, 0,
        "[food %d, linemate %d, deraumere %d, sibur %d, mendiane %d,"
        " phiras %d,thystame %d]", inventory->food, inventory->linemate,
        inventory->deraumere, inventory->sibur, inventory->mendiane,
        inventory->phiras, inventory->thystame);
    char *str = malloc(sizeof(char) * (size + 1));

    snprintf(str, size,
        "[food %d, linemate %d, deraumere %d, sibur %d, mendiane %d,"
        " phiras %d,thystame %d]", inventory->food, inventory->linemate,
        inventory->deraumere, inventory->sibur, inventory->mendiane,
        inventory->phiras, inventory->thystame);
    return str;
}
