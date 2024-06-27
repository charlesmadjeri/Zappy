/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

/*typedef enum ressource_s {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
} ressource_t;*/

/*player_inventory*/
typedef struct inventory_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} inventory_t;


#endif /* !INVENTORY_H_ */
