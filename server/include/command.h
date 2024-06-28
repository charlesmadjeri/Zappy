/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** command
*/

#pragma once

#include "zappy.h"
#include "client.h"

typedef struct client_s client_t;

typedef struct linked_command_s {
    char **command;
    struct linked_command_s *next;
} linked_command_t;

void append_new_commands(char **new_command, linked_command_t **list);

linked_command_t *pop_command(linked_command_t *node);

int count_commands(linked_command_t *node, int len);

void first_command(char **command, client_t *client, game_t *game);
