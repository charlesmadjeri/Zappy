/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** handle_command
*/

#include "command.h"
#include "game.h"
#include "map.h"
#include "inventory.h"
#include "client.h"


void gui_init_message(client_t *client, game_t *game)
{
    char new_line[BUFF_SIZE_GUI];
    char message[BUFF_SIZE_GUI];

    sprintf(new_line, "msz %d %d\n", game->map.x, game->map.y);
    strcat(message, new_line);
    for (int i = 0; i < game->map.x; i++) {
        for (int j = 0; j < game->map.y; j++) {
            sprintf(new_line, "btc %d %d %d %d %d %d %d %d %d\n", i, j,
            game->map.tile[i][j].food,
            game->map.tile[i][j].linemate,
            game->map.tile[i][j].deraumere,
            game->map.tile[i][j].sibur,
            game->map.tile[i][j].mendiane,
            game->map.tile[i][j].phiras,
            game->map.tile[i][j].thystame);
            strcat(message, new_line);
        }
    }
    strncpy(client->write, message, BUFF_SIZE_GUI - 1);
    client->write[BUFF_SIZE_GUI - 1] = '\0';
}

void assign_player(char **command, client_t *client, game_t *game)
{
    char *team = command[0];
    int i = 0;

    for (; i < game->nb_teams; i++) {
        if (strcmp(team, game->teams[i]) == 0)
            break;
    }
    if (i >= game->nb_teams) {
        strcpy(client->write, "ko\n");
    }
    create_player(game->teams[i], client->player, game);
    client->player->state = ALIVE;
    sprintf(client->write, "%d\n %d %d\n", client->player->id,
    game->map.x, game->map.y);
}

void first_command(char **command, client_t *client, game_t *game)
{
    char *message;

    if (strcmp(command[0], "GRAPHIC") == 0) {
        create_player("GUI", client->player, game);
        gui_init_message(client, game);
        dprintf(client->fd, client->write);
        game->tv.tv_sec = 1;
    } else {
        assign_player(command, client, game);
        dprintf(client->fd, client->write);
    }
}
