/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Main
*/

#include <getopt.h>
#include <iostream>
#include "GUI.hpp"

void print_help(void)
{
    std::cout << "USAGE: ./zappy_gui" << std::endl;
    std::cout << "        --help  nbParams[0] isMandatory : 0" << std::endl;
    std::cout << "        -h <host> is the name of the host; localhost by default nbParams[1] isMandatory : 0" << std::endl;
    std::cout << "        -p <port> is the port number nbParams[1] isMandatory : 0" << std::endl;
}

int parse_params(int ac, char **av, GUIClient::Communication &comm)
{
    const option longopts[] = {
        {"help", no_argument, nullptr, 0},
        {nullptr, no_argument, nullptr, 0}
    };
    int opt;

    while (true) {
        opt = getopt_long(ac, av, "h:p:", longopts, nullptr);
        if (opt == -1)
            break;
        switch (opt) {
            case 0: print_help(); return 1;
            case 'h': comm.setHost(optarg); break;
            case 'p': comm.setPortFromString(optarg); break;
            default: continue;
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    GUIClient::GUI gui = GUIClient::GUI();
    GUIClient::Communication &comm = gui.getCommunication();

    if (parse_params(ac, av, comm) == 1)
        return 0;
    int status = comm.connectToServer();
    if (status == -1)
        return 84;
    gui.run();
    std::cout << "Closing GUI." << std::endl;
    return 0;
}
