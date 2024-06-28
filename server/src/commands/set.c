/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** take
*/

#include "ai_commands.h"

static char *end_condition(inventory_t *current,
    player_t *player, char *object)
{
    if (strcmp(object, "mendiane") == 0) {
        if (player->inventory.mendiane > 0) {
            player->inventory.mendiane--;
            current->mendiane++;
        }
    }
    if (strcmp(object, "phiras") == 0) {
        if (player->inventory.phiras > 0) {
            player->inventory.phiras--;
            current->phiras++;
        }
    }
    if (strcmp(object, "thystame") == 0) {
        if (player->inventory.thystame > 0) {
            player->inventory.thystame--;
            current->thystame++;
        }
    } else
        return "ko";
    return "ok";
}

static char *snd_condition(inventory_t *current,
    player_t *player, char *object)
{
    if (strcmp(object, "linemate") == 0) {
        if (player->inventory.linemate > 0) {
            player->inventory.linemate--;
            current->linemate++;
        }
    }
    if (strcmp(object, "deraumere") == 0) {
        if (player->inventory.deraumere > 0) {
            player->inventory.deraumere--;
            current->deraumere++;
        }
    }
    if (strcmp(object, "sibur") == 0) {
        if (player->inventory.sibur > 0) {
            player->inventory.sibur--;
            current->sibur++;
        }
    } else
        return end_condition(current, player, object);
    return "ok";
}

char *set(map_t *map, player_t *player, char *object)
{
    inventory_t *current = &map->tile[player->coords[0]][player->coords[1]];

    if (strcmp(object, "food") == 0) {
        if (player->inventory.food > 0) {
            player->inventory.food--;
            current->food++;
        }
    } else {
        return snd_condition(current, player, object);
    }
    return "ok";
}
