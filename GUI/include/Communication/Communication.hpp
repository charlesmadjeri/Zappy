/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Communication
*/

#pragma once

#include <iostream>
#include <sstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <fcntl.h>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Tile.hpp"
#include "utils.hpp"
#include "Incantation.hpp"

#define BUFFER_SIZE 4096

namespace GUIClient {
    class GUI;
    class Communication {
        enum Commands {
            MSZ = 0,
            BCT = 1,
            TNA = 2,
            PNW = 3,
            PPO = 4,
            PLV = 5,
            PIN = 6,
            PEX = 7,
            PBC = 8,
            PIC = 9,
            PIE = 10,
            PFK = 11,
            PDR = 12,
            PGT = 13,
            PDI = 14,
            ENW = 15,
            EBO = 16,
            EDI = 17,
            SGT = 18,
            SST = 19,
            SEG = 20,
            SMG = 21,
            SUC = 22,
            SBP = 23,
            EHT = 24
        };

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

            std::string attemptRead();

            sf::Vector2i requestMapSize();
            int requestPlayerLevel(int playerId);
            Ressources requestPlayerInventory(int playerId);
            Ressources requestTileContent(int x, int y);
            void runCommand(Commands command, std::vector<std::string> &args, GUI &gui);
            void handleCommunications(GUI &gui);
        protected:
        private:
            socket_t _socket;
            sockaddr_in _addr;
            u_short _port;
            std::string _host;
            char _buffer[BUFFER_SIZE] = {0};

            std::string _requestData(const std::string &request) const;
            void _sendData(const std::string &request) const;
            std::vector<std::string> _splitData(std::string args) const;

            sf::Vector2i _getMapSizeFromCommand(const std::vector<std::string> &command);
            TileComponent _getTileContentFromCommand(const std::vector<std::string> &command);
            Player _getNewPlayerFromCommand(const std::vector<std::string> &command);
            Player::Position _getPlayerPositionFromCommand(const std::vector<std::string> &command);
            Ressources _getPlayerInventoryFromCommand(const std::vector<std::string> &command);
            IncantationComponent _getIncantationFromCommand(const std::vector<std::string> &command);
            std::vector<int> _convertPlayerIDs(const std::vector<std::string> &playerIDs);

            static const std::map<std::string, Commands> _commands;
    };
}

