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
        exit(0);
    }
}

void main_loop(server_t *server)
{
    fd_set readfd;
    fd_set writefd;
    sockaddr_in_t addrCLient;
    int socketClient = -1;
    int addrClient;
    ssize_t readval = 0;
    char buffer[8056];

    while (server->status == false) {
        if (socketClient == -1) {
            printf("waiting for connection...\n");
            socketClient = accept(server->sockfd, (struct sockaddr *)&addrCLient, &server->socket_size);
            printf("connection accepted\n");
            dprintf(socketClient, "WELCOME\n");
            printf("Server ---> WELCOME\n");
            read(socketClient, buffer, 8057);
            printf("%s", buffer);
            if (strcmp(buffer, "GRAPHIC\n") == 0) {
                printf("Client ---> GUI online\n");
                server->status = true;
            } else {
                printf("Client ---> Player online\n");
                server->status = true;
            }
        }
    }
}

int main_server(int ac, char **av)
{
    server_t server = {.addr_serv = {0}};
    if (ac >= 2 && strcmp(av[1], "-h") == 0)
        help();
    signal(SIGINT, sig_int_catcher);
    init_serv(ac, av, &server);
    start_server(&server);
    main_loop(&server);
    return (0);
}
