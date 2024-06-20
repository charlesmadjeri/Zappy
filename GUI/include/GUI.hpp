/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUI
*/

#pragma once

#include <memory>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "EventHandler.hpp"

namespace GUIClient {
    class GUI {
        public:
            GUI();
            ~GUI() = default;

            void setHost(const char *host);
            void setHost(std::string &host);

            void setPort(u_short port);
            void setPortFromString(const char *port);
            void setPortFromString(std::string &port);

            sf::Socket::Status connectToServer();
            void run();

            sf::RenderWindow &getWindow() const { return *_window; }
            sf::Event &getEvent();
        protected:
        private:
            sf::TcpSocket _socket;
            sf::IpAddress _ip;
            sockaddr_in _addr;
            u_short _port;
            std::string _host;

            std::shared_ptr<sf::RenderWindow> _window;
            EventHandler _eventHandler;
            std::shared_ptr<Map> _map;
    };

    #define FONT_PATH   "../assets/font.ttf"
    #define WIN_H       600
    #define WIN_W       800
}
