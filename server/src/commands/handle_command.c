/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** handle_command
*/

#include "command.h"
#include "game.h"
#include "client.h"

bool is_team(char *team, game_t *game)
{
    for (int i = 0; i < game->nb_teams; i++) {
        if (strcmp(team, game->teams[i]) == 0)
            return (true);
    } 
    return false;
}

void assign_player(char **command, client_t *client, game_t *game)
{

}

void put_message(char *dest, char *src)
{

}

void first_command(char **command, client_t *client, game_t *game)
{
    char *message;

    sprintf(message, "msz 10 10\nsgt 100\nbct 5 5 1 0 0 0 0 0\n");
    if (strcmp(command[0], "GRAPHIC" ) == 0) {
        create_player("GUI", client->player, game);
        strcpy(client->write, message);
        dprintf(client->fd, client->write);
    } else {
        assign_player(command, client, game);
    }
}