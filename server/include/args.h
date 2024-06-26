/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** args
*/

#ifndef ARGS_H_
    #define ARGS_H_

    #include "server.h"

/**
 * @brief Get the port object
 *
 * @param ac
 * @param av
 * @return int
 */
int get_port(int ac, char **av);

/**
 * @brief Get the freq object
 *
 * @param ac
 * @param av
 * @return int
 */
int get_freq(int ac, char **av);

/**
 * @brief Get the width object
 *
 * @param ac
 * @param av
 * @return int
 */
int get_width(int ac, char **av);

/**
 * @brief Get the height object
**
 * @param ac
 * @param av
 * @return int
 */
int get_height(int ac, char **av);

/**
** @brief Get the clientnb object
**
** @param ac
** @param av
** @return int
*/
int get_clientnb(int ac, char **av);

/**
** @brief
**
**/
void get_teams(int ac, char **av, int i, game_t *game);

#endif /* !ARGS_H_ */
