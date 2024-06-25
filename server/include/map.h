/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "server.h"

    typedef struct map_s {
        int x;
        int y;
        inventory_t **tile;
    } map_t;


#endif /* !MAP_H_ */
