/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** init
*/

#include "server.h"
#include "map.h"
#include "args.h"

void init_teams(int ac, char **av, game_t *game)
{
    int i = 0;

    for (; i != ac; i++) {
        if (strcmp(av[i], "-n") == 0) {
            break;
        }
    }
    if (i < ac) {
        get_teams(ac, av, i, game);
    } else {
        print_error("invalid argurment \"-n\", expect a value");
    }
}

void init_game(int ac, char **av, game_t *game)
{
    game->freq = get_freq(ac, av);
    game->id_count = 0;
    init_loot(&game->loot);
    game->map = create_world(get_width(ac, av), get_height(ac, av));
    game->nb_cli = get_clientnb(ac, av);
    game->time = clock();
    init_teams(ac, av, game);
    printf("nb_teams = %d\nteams =", game->nb_teams);
    for (int i = 0; game->teams[i] != NULL; i++)
        printf(" %s", game->teams[i]);
    printf("\n");
}
