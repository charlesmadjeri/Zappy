/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_command
*/

#include "server.h"
#include "game.h"
#include "command.h"

void create_command(char *buffer, client_t *client, game_t *game)
{
    char *token;
    char** command = malloc(sizeof(char *));

    token = strtok(buffer, " ");
    for (int i = 0; token != NULL; i++) {
        command[i] = token;
        command[i + 1] = NULL;
        token = strtok(NULL, " ");
    }
    if (client->player == NULL) {
        first_command(command, client, game);
    } else {

    }
    for (int i = 0; command[i] != NULL; i++) {

    }
}

void get_command(char *buffer, int valread, client_t *client, game_t *game)
{
    char tmp_buff[BUFF_SIZE];
    int count = 0;

    if (valread <= 0) {
        client->status = false;
        return;
    }
    buffer[valread] = '\0';
    strncpy(tmp_buff, buffer, BUFF_SIZE - 1);
    tmp_buff[BUFF_SIZE -1] = '\0';
    for (int i = 0; buffer[i]; i++) {
        tmp_buff[i] = buffer[i];
        if (buffer[i] == '\n') {
            count ++;
            tmp_buff[i] = '\0';
            create_command(tmp_buff, client, game);
        }
        if (count >= 10)
            return;
    }
}