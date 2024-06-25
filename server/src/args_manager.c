/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** args_manager
*/

#include "server.h"

int get_port(int ac, char **av)
{
    int port = 1024;
    int i = 0;

    for (; i != ac; i++) {
        if (strcmp(av[i], "-p") == 0) {
            break;
        }
    }
    if (i + 1 >= ac) {
        print_error("invalid argurment \"-p\", expect a value");  
    } else if (atoi(av[i+1]) <= 0) {
        print_error("invalid argurment \"-p\", expect an integer");
    }
    port = atoi(av[i+1]);
    return (port);
}

void get_freq(int ac, char **av)
{
    int freq = 100;
    int i = 0;

    for (; i != ac; i++) {
        if (strcmp(av[i], "-f") == 0) {
            break;
        }
    }
    if (i == ac) {
        return (freq);  
    } else if (i + 1 == ac || atoi(av[i+1]) <= 0) {
        print_error("invalid argurment \"-f\", expect an integer");
    }
    freq = atoi(av[i+1]);
    return (freq);
}

int get_width(int ac, char **av)
{
    int width = 0;
    int i = 0;

    for (; i != ac; i++) {
        if (strcmp(av[i], "-x") == 0) {
            break;
        }
    }
    if (i + 1 >= ac) {
        print_error("invalid argurment \"-x\", expect a value");  
    } else if (atoi(av[i+1]) <= 0) {
        print_error("invalid argurment \"-x\", expect an integer");
    }
    width = atoi(av[i+1]);
    return (width);
}

int get_height(int ac, char **av)
{
    int height = 0;
    int i = 0;

    for (; i != ac; i++) {
        if (strcmp(av[i], "-y") == 0) {
            break;
        }
    }
    if (i + 1 >= ac) {
        print_error("invalid argurment \"-y\", expect a value");  
    } else if (atoi(av[i+1]) <= 0) {
        print_error("invalid argurment \"-y\", expect an integer");
    }
    height = atoi(av[i+1]);
    return (height);
}

int get_clientsNb(int ac, char **av)
{
    int number = 0;
    int i = 0;

    for (; i != ac; i++) {
        if (strcmp(av[i], "-c") == 0) {
            break;
        }
    }
    if (i + 1 >= ac) {
        print_error("invalid argurment \"-c\", expect a value");  
    } else if (atoi(av[i+1]) <= 0) {
        print_error("invalid argurment \"-c\", expect an integer");
    }
    number = atoi(av[i+1]);
    return (number);
}