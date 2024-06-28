/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** main_server
*/

#include "game.h"
#include "server.h"

void help(void)
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

void sig_int_catcher(int sig)
{
    if (sig == SIGINT) {
        printf("\nServer is closing by signal\n");
        exit(0);
    }
}

void main_loop(server_t *server, game_t *game)
{
    fd_set readfd;
    fd_set writefd;

    while (server->status == false) {
        reset_fd(server, &readfd, &writefd);
        select(FD_SETSIZE, &readfd, &writefd, NULL, NULL);
        manage_connection(server, &readfd);
        manage_message(server, game, &readfd);
    }
}

int main_server(int ac, char **av)
{
    game_t game;
    server_t server;

    if (ac >= 2 && strcmp(av[1], "--help") == 0)
        help();
    printf("======ZAPPY SERVER======\n");
    signal(SIGINT, sig_int_catcher);
    init_game(ac, av, &game);
    init_server(ac, av, &server);
    start_server(&server);
    printf("========================\n");
    main_loop(&server, &game);
    free_memory(&server, &game);
    return (0);
}
