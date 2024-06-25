/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** init
*/

#include "server.h"
#include "args.h"

void init_loot(inventory_t *loot)
{
    loot->food = 0;
    loot->linemate = 0;
    loot->deraumere = 0;
    loot->sibur = 0;
    loot->mendiane = 0;
    loot->phiras = 0;
    loot->thystame = 0;
}

void make_map(game_t *game)
{
    game->map.tile = malloc(sizeof(inventory_t *) * (game->map.x + 1));
    if (game->map.tile == NULL)
        print_error("Malloc map failed");
    for (int i = 0; i != game->map.x; i++) {
        game->map.tile[i] = malloc(sizeof(inventory_t) *(game->map.y + 1));
        break;
        if (game->map.tile[i] == NULL)
            print_error("Malloc map failed");
        for (int j = 0; j != game->map.y; j++) {
            init_loot(&game->map.tile[i][j]);
        }
    }
}

void init_game(int ac, char **av, game_t *game)
{
    game->freq = get_freq(ac, av);
    game->id_count = 0;
    init_loot(&game->loot);
    game->map.x = get_width(ac, av);
    game->map.y = get_height(ac, av);
    game->nb_teams = get_clientsNb(ac, av);
    game->time = clock();
    make_map(game);

}
