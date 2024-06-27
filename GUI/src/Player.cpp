/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Player
*/

#include <iostream>
#include "Player.hpp"
#include "Team.hpp"

void GUIClient::Player::setTeam(std::shared_ptr<Team> team)
{
    this->_team = team;
    this->_team->addPlayer(*this);
}
