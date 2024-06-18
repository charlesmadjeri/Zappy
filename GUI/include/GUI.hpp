/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUI
*/

#pragma once

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>

namespace GUI {
    class GUI {
        public:
            GUI();
            ~GUI();

            void setHost(const char *host);
            void setHost(std::string &host);

            void setPort(int port);
            void setPortFromString(const char *port);
            void setPortFromString(std::string &port);

            int connectToServer();
            void run(int serverSocket);
        protected:
        private:
            sockaddr_in _addr;
    };
}
