/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

/*----------INCLUDES----------*/
    #include "inventory.h"

/*----------MACROS----------*/
    #define F_DENSITY 0.5
    #define L_DENSITY 0.3
    #define D_DENSITY 0.15
    #define S_DENSITY 0.1
    #define M_DENSITY 0.1
    #define P_DENSITY 0.08
    #define T_DENSITY 0.05

/*----------TYPEDEFS----------*/
typedef struct map_s {
    int x;
    int y;
    inventory_t **tile;
} map_t;

typedef struct resource_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int total_resources;
} resource_t;


#endif /* !MAP_H_ */
