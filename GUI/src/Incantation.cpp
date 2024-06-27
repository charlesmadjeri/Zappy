/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Incantation
*/

#include "Incantation.hpp"

GUIClient::Incantation::Incantation(int x, int y, int level) : IncantationComponent(x, y, level)
{
    this->_triangle.setPointCount(3);
    this->_triangle.setFillColor(sf::Color::Magenta);
    this->_triangle.setPosition(x, y);
}

void GUIClient::Incantation::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_triangle, states);
}
