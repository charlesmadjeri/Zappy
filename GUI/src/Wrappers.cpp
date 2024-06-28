/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Wrappers
*/

#include "Wrappers.hpp"
#include "Player.hpp"
#include "macros.hpp"

std::shared_ptr<GUIClient::Player> &Wrappers::Players::operator[](std::size_t idx)
{
    for (std::shared_ptr<GUIClient::Player> &player : *this) {
        if ((std::size_t) player->getId() == idx)
            return player;
    }
    throw std::out_of_range("Index out of range");
}

void Wrappers::Players::updatePlayerTextInfos()
{
    int i = 0;

    for (std::shared_ptr<GUIClient::Player> &player : *this) {
        player->getTextInfos().setPosition(WIN_H + 10, WIN_H / 3 + 25 + i * 25);
        player->update();
        i++;
    }
}
