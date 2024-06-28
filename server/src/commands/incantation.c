/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** basic_commands
*/

#include "ai_commands.h"

static char *first_level(map_t *map, player_t *player)
{
    if (map->tile[player->coords[0]][player->coords[1]].linemate >= 1)
        return "ok";
    return "ko";
}

static char *second_level(map_t *map, player_t *player, int count)
{
    inventory_t current = map->tile[player->coords[0]][player->coords[1]];

    if (current.linemate >= 1 && current.deraumere >= 1 && current.sibur >= 1
        && count >= 2)
        return "ok";
    return "ko";
}

static char *third_level(map_t *map, player_t *player, int count)
{
    inventory_t current = map->tile[player->coords[0]][player->coords[1]];

    if (current.linemate >= 2 && current.phiras >= 2 && current.sibur >= 1
        && count >= 2)
        return "ok";
    return "ko";
}

static char *fourth_level(map_t *map, player_t *player, int count)
{
    inventory_t current = map->tile[player->coords[0]][player->coords[1]];

    if (current.linemate >= 1 && current.deraumere >= 1 && current.sibur >= 2
        && current.phiras >= 1 && count >= 4)
        return "ok";
    return "ko";
}

static char *fifth_level(map_t *map, player_t *player, int count)
{
    inventory_t current = map->tile[player->coords[0]][player->coords[1]];

    if (current.linemate >= 1 && current.deraumere >= 2 && current.sibur >= 1
        && current.mendiane >= 3 && count >= 4)
        return "ok";
    return "ko";
}

static char *sixth_level(map_t *map, player_t *player, int count)
{
    inventory_t current = map->tile[player->coords[0]][player->coords[1]];

    if (current.linemate >= 1 && current.deraumere >= 2 && current.sibur >= 3
        && current.phiras >= 1 && count >= 6)
        return "ok";
    return "ko";
}

static char *seventh_level(map_t *map, player_t *player, int count)
{
    inventory_t current = map->tile[player->coords[0]][player->coords[1]];

    if (current.linemate >= 2 && current.deraumere >= 2 && current.sibur >= 2
        && current.mendiane >= 2 && current.phiras >= 2 && count >= 6
        && current.thystame >= 1)
        return "ok";
    return "ko";
}

static int count_clients_on_tile(linked_client_t *client,
    int x, int y, int count)
{
    if (client->client.player->coords[0] == x
        && client->client.player->coords[1] == y)
        count++;
    if (client->next != NULL)
        count = count_clients_on_tile(client, x, y, count);
    return count;
}

static char *end_switch(map_t *map, player_t *player, int count)
{
    switch (player->level) {
        case 5:
            return fifth_level(map, player, count);
        case 6:
            return sixth_level(map, player, count);
        case 7:
            return seventh_level(map, player, count);
        default:
            return "ko";
    }
}

char *incantation(map_t *map, player_t *player, server_t *server)
{
    int count = count_clients_on_tile(server->clients,
        player->coords[0], player->coords[1], 0);

    switch (player->level) {
        case 1:
            return first_level(map, player);
        case 2:
            return second_level(map, player, count);
        case 3:
            return third_level(map, player, count);
        case 4:
            return fourth_level(map, player, count);
        default:
            return end_switch(map, player, count);
    }
}
