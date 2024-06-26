/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** map
*/

#include "resources.h"
#include <stdlib.h>

static int *fst_init_list(resource_t *resource, int *index, int *resource_list)
{
    for (int i = 0; i < resource->food; i++) {
        resource_list[*index] = 0;
        *index++;
    }
    for (int i = 0; i < resource->linemate; i++) {
        resource_list[*index] = 0;
        *index++;
    }
    for (int i = 0; i < resource->deraumere; i++) {
        resource_list[*index] = 0;
        *index++;
    }
    resource_list = snd_init_list(resource, index, resource_list);
    return resource_list;
}

static int *snd_init_list(resource_t *resource, int *index, int *resource_list)
{
    for (int i = 0; i < resource->sibur; i++) {
        resource_list[*index] = 0;
        index++;
    }
    for (int i = 0; i < resource->mendiane; i++) {
        resource_list[*index] = 0;
        index++;
    }
    for (int i = 0; i < resource->phiras; i++) {
        resource_list[*index] = 0;
        index++;
    }
    for (int i = 0; i < resource->thystame; i++) {
        resource_list[*index] = 0;
        index++;
    }
    return resource_list;
}

int *init_resource_list(resource_t *resource, int nb_tiles)
{
    int index = 0;
    int *resource_list = {0};

    if (resource->total_resources < nb_tiles)
        resource->total_resources = nb_tiles;
    resource_list = malloc(sizeof(int) * resource->total_resources);
    resource_list = fst_init_list(resource, &index, resource_list);
    for (; index < nb_tiles; index ++) {
        resource_list[index] = 0;
        index++;
    }
    return resource_list;
}
