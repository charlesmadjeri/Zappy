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

static bool eject_switch(linked_client_t *client, int direction)
{
    switch (direction) {
        case RIGHT:
            client->client.player->coords[0] ++;
            break;
        case LEFT:
            client->client.player->coords[0] --;
            break;
        case UP:
            client->client.player->coords[1] --;
            break;
        case DOWN:
            client->client.player->coords[1] ++;
            break;
        default:
            return false;
    }
    return true;
}

static bool eject_clients_on_tile(linked_client_t *client,
    int x, int y, int direction)
{
    bool result = true;

    if (client->client.player->coords[0] == x
        && client->client.player->coords[1] == y) {
        if (eject_switch(client, direction) == false)
            result = false;
    }
    if (client->next != NULL) {
        if (eject_clients_on_tile(client, x, y, direction) == true)
            result = true;
    }
    return result;
}

char *eject(player_t *player, server_t *server)
{
    if (eject_clients_on_tile(server->clients, player->coords[0],
        player->coords[1], player->direction) == true)
        return "ok";
    return "ko";
}
