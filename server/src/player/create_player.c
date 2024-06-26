/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** create_player
*/

#include "player.h"
#include "resources.h"

void init_inventory(inventory_t *inventory)
{
    inventory->deraumere = 0;
    inventory->food = 0;
    inventory->linemate = 0;
    inventory->mendiane = 0;
    inventory->phiras = 0;
    inventory->sibur = 0;
    inventory->thystame = 0;
}

int *rand_coords(game_t *game)
{
    int *coords = malloc(sizeof(int) * 2);

    srand(time(NULL));
    coords[0] = rand() % game->map.x;
    coords[1] = rand() % game->map.y;
    return coords;
}

void create_player(char *team_name, player_t *player, game_t *game)
{
    player = malloc(sizeof(player_t));
    player->id = game->id_count;
    game->id_count++;
    init_inventory(&player->inventory);
    player->level = 1;
    player->state = NONE;
    player->team_name = team_name;
    player->coords = rand_coords(game);
    player->direction = rand() % 4;
}
