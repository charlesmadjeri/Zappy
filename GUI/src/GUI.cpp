/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUI
*/

#include "GUI.hpp"
#include <unistd.h>

GUI::GUI::GUI()
{
    this->_addr.sin_family = AF_INET;
}

GUI::GUI::~GUI()
{
}

void GUI::GUI::setHost(const char *host)
{
    this->_addr.sin_addr.s_addr = inet_addr(host);
}

void GUI::GUI::setHost(std::string &host)
{
    this->_addr.sin_addr.s_addr = inet_addr(host.c_str());
}

void GUI::GUI::setPort(int port)
{
    this->_addr.sin_port = htons(port);
}

void GUI::GUI::setPortFromString(const char *port)
{
    this->_addr.sin_port = htons((int) std::strtol(port, nullptr, 10));
}

void GUI::GUI::setPortFromString(std::string &port)
{
    this->_addr.sin_port = htons((int) std::strtol(port.c_str(), nullptr, 10));
}

/// @brief Connect to the server using the host and port set in the GUI.
/// @return The file descriptor of the socket.
int GUI::GUI::connectToServer()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "Connecting to server..." << std::endl;
    int result = connect(sock, (struct sockaddr *)&this->_addr, sizeof(this->_addr));

    if (result != 0) {
        std::cerr << "Couldn't connect to server!" << std::endl;
        return -1;
    }

    write(sock, "GRAPHIC\n", 8);
    std::cout << "Connected to server!" << std::endl;
    return sock;
}

void GUI::GUI::run(int serverSocket)
{
    while (true) {
        ;
    }
}
