/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** EventHandler
*/

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

namespace GUIClient {
    class EventHandler {
        public:
            EventHandler() = default;
            EventHandler(std::shared_ptr<sf::RenderWindow> &window);
            ~EventHandler() = default;

            sf::Event &getEvent() { return _event; };
            int pollEvents();
        protected:
        private:
            sf::Event _event;
            std::shared_ptr<sf::RenderWindow> _window;

    };
}
