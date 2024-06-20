/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Player
*/

#include <iostream>
#include "Player.hpp"

GUIClient::Inventory &GUIClient::Player::getInventoryFromServer()
{
    std::cout << "pin " << this->_id << "\n" << std::endl;
    // return Inventory();
}

GUIClient::Inventory &GUIClient::Player::getInventory()
{
    return this->_inventory;
}

int GUIClient::Player::getX() const
{
    return this->_x;
}

int GUIClient::Player::getY() const
{
    return this->_y;
}

sf::Vector2f GUIClient::Player::getPos() const
{
    return sf::Vector2f(this->_x, this->_y);
}

int GUIClient::Player::getLevel() const
{
    return this->_level;
}

int GUIClient::Player::getId() const
{
    return this->_id;
}
