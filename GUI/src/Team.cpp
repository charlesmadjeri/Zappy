/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Team
*/

#include "Team.hpp"

GUIClient::Team::Team(std::string &name)
{
    this->_name = name;
}

void GUIClient::Team::addPlayer(GUIClient::Player &player)
{
    this->_players.push_back(std::make_shared<Player>(player));
}

void GUIClient::Team::removePlayer(int id)
{
    this->_players.remove(this->_players[id]);
}
