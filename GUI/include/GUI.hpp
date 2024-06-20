/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUI
*/

#pragma once

#include <memory>
#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "EventHandler.hpp"
#include "Communication.hpp"

namespace GUIClient {
    class GUI {
        public:
            GUI();
            ~GUI() = default;

            void run();

            sf::RenderWindow &getWindow() const { return *_window; }
            sf::Event &getEvent();
            Communication &getCommunication() { return _communication; }
        protected:
        private:
            std::shared_ptr<sf::RenderWindow> _window;
            EventHandler _eventHandler;
            Communication _communication;
            std::shared_ptr<Map> _map;
    };

    #define FONT_PATH   "../assets/font.ttf"
    #define WIN_H       600
    #define WIN_W       800
}
