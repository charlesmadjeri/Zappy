/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** EventHandler
*/

#include "EventHandler.hpp"
#include <iostream>

GUIClient::EventHandler::EventHandler(std::shared_ptr<sf::RenderWindow> &window)
{
    this->_window = window;
}

int GUIClient::EventHandler::pollEvents()
{
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed) {
            this->_window->close();
            return -1;
        }
    }
    return 0;
}
