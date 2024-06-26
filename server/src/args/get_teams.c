/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_teams
*/

#include "server.h"

bool check_duplicate_teams(game_t *game, int i)
{
        for (int j = i + 1; game->teams[j] != NULL; j++) {
            if (strcmp(game->teams[i], game->teams[j]) == 0) {
                return true;
            }
        }
    return false;
}

void get_teams(int ac, char **av, int i, game_t *game)
{
    game->nb_teams = 0;
    for (int j = i + 1; j < ac && av[j][0] != '-'; j++) {
        game->nb_teams++;
    }
    game->teams = malloc(sizeof(char *) * (game->nb_teams + 1));
    if (game->teams == NULL) {
        print_error("Malloc teams failed\n");
    }
    for (int k = 0; k < game->nb_teams; k++) {
        game->teams[k] = strdup(av[i + 1 + k]);
        if (game->teams[k] == NULL) {
            print_error("Malloc teams failed\n");
        }
    }
    game->teams[game->nb_teams] = NULL;
    for (int i = 0; game->teams[i] != NULL; i++) {
        if (check_duplicate_teams(game, i))
            print_error("Duplicate team names found");
    }
}
