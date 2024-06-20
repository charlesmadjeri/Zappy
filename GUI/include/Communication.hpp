/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Communication
*/

#pragma once

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <SFML/Graphics.hpp>
#include "Player.hpp"

namespace GUIClient {
    class Communication {
        public:
            typedef int socket_t;

            Communication();
            ~Communication() = default;

            void setHost(const char *host);
            void setHost(std::string &host);

            void setPort(u_short port);
            void setPortFromString(const char *port);
            void setPortFromString(std::string &port);

            int connectToServer();
            const socket_t &getSocket() const { return _socket; };

            sf::Vector2i getMapSize();
            int getPlayerLevel(int playerId);
        protected:
        private:
            socket_t _socket;
            sockaddr_in _addr;
            u_short _port;
            std::string _host;

            std::string _requestData(const std::string &request) const;
            void _sendData(const std::string &request) const;
            std::vector<std::string> _splitData(std::string args) const;

    };
}
