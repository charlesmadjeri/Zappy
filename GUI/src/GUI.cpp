/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUI
*/

#include "GUI.hpp"
#include <unistd.h>

GUIClient::GUI::GUI()
{
    this->_addr.sin_family = AF_INET;
    this->_window = std::make_shared<sf::RenderWindow>();
    this->_map = std::make_shared<GUIClient::Map>(2, 2);
    this->_eventHandler = EventHandler(this->_window);
    this->_socket.setBlocking(false);
}

inline sf::Event &GUIClient::GUI::getEvent()
{
    return this->_eventHandler.getEvent();
}

void GUIClient::GUI::setHost(const char *host)
{
    // this->_addr.sin_addr.s_addr = inet_addr(host);
    this->_host = host;
    this->_ip = sf::IpAddress(host);
}

void GUIClient::GUI::setHost(std::string &host)
{
    // this->_addr.sin_addr.s_addr = inet_addr(host.c_str());
    this->_host = host;
    this->_ip = sf::IpAddress(host);
}

void GUIClient::GUI::setPort(u_short port)
{
    // this->_addr.sin_port = htons(port);
    this->_port = port;
}

void GUIClient::GUI::setPortFromString(const char *port)
{
    this->_port = (u_short) std::strtol(port, nullptr, 10);
    // this->_addr.sin_port = htons(this->_port);

}

void GUIClient::GUI::setPortFromString(std::string &port)
{
    this->_port = (u_short) std::strtol(port.c_str(), nullptr, 10);
    // this->_addr.sin_port = htons(this->_port);
}

/// @brief Connect to the server using the host and port set in the GUI.
/// @return The status of the connection.
sf::Socket::Status GUIClient::GUI::connectToServer()
{
    // int sock = socket(AF_INET, SOCK_STREAM, 0);
    // std::cout << "Connecting to server... [" << this->_host << ":" << this->_port << "]" << std::endl;
    // int result = connect(sock, (struct sockaddr *)&this->_addr, sizeof(this->_addr));

    // if (result != 0) {
    //     std::cerr << "Couldn't connect to server!" << std::endl;
    //     return -1;
    // }

    // send(sock, "GRAPHIC\n", 8, 0);
    // std::cout << "Connected to server!" << std::endl;
    // return sock;
    sf::Socket::Status status = this->_socket.connect(this->_ip, this->_port, sf::milliseconds(5000));
    if (status != sf::Socket::Status::Error)
        status = this->_socket.send("GRAPHIC\n", 8);
    return status;
}

void GUIClient::GUI::run()
{
    sf::Packet packet;
    this->_window->create(sf::VideoMode(WIN_W, WIN_H), "Zappy GUI");

    while (this->_window->isOpen()) {
        if (this->_eventHandler.pollEvents() == -1)
            break;
        this->_socket.receive(packet);
        if (packet.getData() != nullptr)
            std::cout << "Received: " << packet.getData() << std::endl;
        this->_window->draw(*this->_map);
        this->_window->display();
        this->_window->clear();
    }
}
