/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** error_manager
*/

#include "stdio.h"
#include <stdlib.h>

void print_error(char *error)
{
    printf("Error : %s\n", error);
    exit(84);
}
