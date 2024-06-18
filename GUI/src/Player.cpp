/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Player
*/

#include <iostream>
#include "Player.hpp"

GUI::Player::Player(int x, int y, int id)
{
    this->_level = 1;
    this->_x = x;
    this->_y = y;
    this->_id = id;
}

GUI::Player::~Player()
{
}

GUI::Inventory GUI::Player::getInventoryFromServer()
{
    std::cout << "pin " << this->_id << "\n" << std::endl;
    return Inventory();
}
