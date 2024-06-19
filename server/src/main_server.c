/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** main_server
*/

#include "server.h"
#include <signal.h>

void help()
{
    printf("USAGE: ./zappy_server -p port -x width -y height"
        "-n name1 name2 ... -c clientsNb -f freq"
        " the server socket listens.\n"
        "\tport\tis the port number\n"
        "\twidth\tis the width of the world\n"
        "\theight\tis the height of the world\n"
        "\tnameX\tis the name of the team X\n"
        "\tclientsNb\tis the number of authorized clients per team\n"
        "\tfreq\tis the reciprocal of time unit for execution of actions\n");
    exit(0);
}

void sig_int_catcher(int sig __attribute__((__unused)))
{
    if (sig == SIGINT) {
        printf("\nServer is closing by signal\n");
        exit_serv = true;
    }
}

int main_server(int ac, char **av)
{
    server_t server = {.addr_serv = {0}};
    if (ac >= 2 && strcmp(av[1], "-h") == 0)
        help();
    signal(SIGINT, sig_int_catcher);
    init_serv(ac, av, server);
    start_server(&server);
    return (0);
}
