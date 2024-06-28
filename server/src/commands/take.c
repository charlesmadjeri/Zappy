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
        if (current->mendiane > 0) {
            current->mendiane--;
            player->inventory.mendiane++;
        }
    }
    if (strcmp(object, "phiras") == 0) {
        if (current->phiras > 0) {
            current->phiras--;
            player->inventory.phiras++;
        }
    }
    if (strcmp(object, "thystame") == 0) {
        if (current->thystame > 0) {
            current->thystame--;
            player->inventory.thystame++;
        }
    } else
        return "ko";
    return "ok";
}

static char *snd_condition(inventory_t *current,
    player_t *player, char *object)
{
    if (strcmp(object, "linemate") == 0) {
        if (current->linemate > 0) {
            current->linemate--;
            player->inventory.linemate++;
        }
    }
    if (strcmp(object, "deraumere") == 0) {
        if (current->deraumere > 0) {
            current->deraumere--;
            player->inventory.deraumere++;
        }
    }
    if (strcmp(object, "sibur") == 0) {
        if (current->sibur > 0) {
            current->sibur--;
            player->inventory.sibur++;
        }
    } else
        return end_condition(current, player, object);
    return "ok";
}

char *take(map_t *map, player_t *player, char *object)
{
    inventory_t *current = &map->tile[player->coords[0]][player->coords[1]];

    if (strcmp(object, "food") == 0) {
        if (current->food > 0) {
            current->food--;
            player->inventory.food++;
        }
    } else {
        return snd_condition(current, player, object);
    }
    return "ok";
}
