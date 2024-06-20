/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Communication
*/

#include "Communication.hpp"

GUIClient::Communication::Communication()
{
    this->_addr.sin_family = AF_INET;

}

void GUIClient::Communication::setHost(const char *host)
{
    this->_addr.sin_addr.s_addr = inet_addr(host);
    this->_host = host;
}

void GUIClient::Communication::setHost(std::string &host)
{
    this->_addr.sin_addr.s_addr = inet_addr(host.c_str());
    this->_host = host;
}

void GUIClient::Communication::setPort(u_short port)
{
    this->_addr.sin_port = htons(port);
    this->_port = port;
}

void GUIClient::Communication::setPortFromString(const char *port)
{
    this->_port = (u_short) std::strtol(port, nullptr, 10);
    this->_addr.sin_port = htons(this->_port);

}

void GUIClient::Communication::setPortFromString(std::string &port)
{
    this->_port = (u_short) std::strtol(port.c_str(), nullptr, 10);
    this->_addr.sin_port = htons(this->_port);
}

/// @brief Connect to the server using the host and port set in the Communication class.
/// @return The status of the connection.
int GUIClient::Communication::connectToServer()
{
    char buffer[1024] = {0};
    int result;

    this->_socket = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "Connecting to server... [" << this->_host << ":" << this->_port << "]" << std::endl;
    result = connect(this->_socket, (struct sockaddr *)&this->_addr, sizeof(this->_addr));

    if (result != 0) {
        std::cerr << "Couldn't connect to server!" << std::endl;
        return -1;
    }

    std::cout << "Waiting for server response..." << std::endl;
    if (read(this->_socket, &buffer, 1023) < 0 || strcmp(buffer, "WELCOME\n") != 0)
        return -1;
    this->_sendData("GRAPHIC\n");
    std::cout << "Connected to server!" << std::endl;
    return 0;
}

std::vector<std::string> GUIClient::Communication::_splitData(std::string args) const
{
    std::vector<std::string> splitted;
    std::string tmp;

    while (args.find(' ') != std::string::npos) {
        tmp = args.substr(0, args.find(' '));
        splitted.push_back(tmp);
        args = args.substr(args.find(' ') + 1);
    }
    return splitted;
}

void GUIClient::Communication::_sendData(const std::string &request) const
{
    write(this->_socket, request.c_str(), request.size());
}

std::string GUIClient::Communication::_requestData(const std::string &request) const
{
    char buffer[1024] = {0};
    ssize_t bytesRead;

    write(this->_socket, (void *)request.c_str(), request.size());
    bytesRead = read(this->_socket, &buffer, 1024);
    if (bytesRead == -1)
        return nullptr;
    return std::string(buffer);
}

sf::Vector2i GUIClient::Communication::getMapSize()
{
    std::vector<std::string> data;
    sf::Vector2i mapSize;

    data = this->_splitData(this->_requestData("msz\n"));

    mapSize.x = std::stoi(data[1], nullptr, 10);
    mapSize.y = std::stoi(data[2], nullptr, 10);
    return mapSize;
}

int GUIClient::Communication::getPlayerLevel(int playerId)
{
    std::vector<std::string> data;
    int level;

    data = this->_splitData(this->_requestData("plv #" + std::to_string(playerId) + "\n"));
    level = std::stoi(data[2], nullptr, 10);
    return level;
}
