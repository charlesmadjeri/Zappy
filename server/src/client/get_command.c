/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_command
*/

#include "server.h"

void create_command(char *buffer)
{
    char *token;
    char** command = malloc(sizeof(char *));

    token = strtok(buffer, " ");
    for (int i = 0; token != NULL; i++) {
        command[i] = token;
        command[i + 1] = NULL;
        token = strtok(NULL, " ");
    }
    for (int i = 0; command[i] != NULL; i++)
        printf(" %s ->", command[i]);
    printf('\n');
    
}

void get_command(char *buffer, int valread, client_t *client)
{
    char tmp_buff[BUFF_SIZE];

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
            tmp_buff[i] = '\0';
            create_command(tmp_buff);
        }
    }
}