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
    this->_window = std::make_shared<sf::RenderWindow>();
    this->_map = std::make_shared<GUIClient::Map>();
    this->_eventHandler = EventHandler(this->_window);
}

inline sf::Event &GUIClient::GUI::getEvent()
{
    return this->_eventHandler.getEvent();
}

void GUIClient::GUI::run()
{
    GUIClient::Communication &comm = this->getCommunication();
    char buffer[1024];

    bzero(buffer, 1024);
    this->_window->create(sf::VideoMode(WIN_W, WIN_H), "Zappy GUI");
    this->_map->create(comm.getMapSize());

    while (this->_window->isOpen()) {
        if (this->_eventHandler.pollEvents() == -1)
            break;
        ssize_t bytesRead = read(comm.getSocket(), &buffer, 1023);
        if (bytesRead > 0)
            std::cout << buffer << std::endl;
        this->_window->draw(*this->_map);
        this->_window->display();
        this->_window->clear();
    }
}
