/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** create_player
*/

#include "player.h"
#include "resources.h"

static inventory_t init_inventory(void)
{
    inventory_t inventory;

    inventory.deraumere = 0;
    inventory.food = 0;
    inventory.linemate = 0;
    inventory.mendiane = 0;
    inventory.phiras = 0;
    inventory.sibur = 0;
    inventory.thystame = 0;
    return inventory;
}

int *rand_coords(game_t *game)
{
    srand(time(NULL));
    int *coords = malloc(sizeof(int) * 2);
    coords[0] = rand() % game->map.x;
    coords[1] = rand() % game->map.y;
    return coords;
}

void create_player(char *team_name, player_t *player, game_t *game)
{
    player->id = game->id_count;
    game->id_count++;
    player->direction = 1;
    player->inventory = init_inventory();
    player->level = 1;
    player->state = NONE;
    player->team_name = team_name;
    player->coords = rand_coords(game);
}