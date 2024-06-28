/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Incantation
*/

#include "Incantation.hpp"

GUIClient::Incantation::Incantation(int x, int y, int level) : IncantationComponent(x, y, level)
{
    this->_circle.setPointCount(3);
    this->_circle.setFillColor(sf::Color::Magenta);
    this->_circle.setPosition(x, y);
}

GUIClient::Incantation::Incantation(IncantationComponent &component) : IncantationComponent(component)
{
    this->_circle.setFillColor(sf::Color::Transparent);
    this->_circle.setOutlineColor(sf::Color::Magenta);
    this->_circle.setOutlineThickness(-3);
    this->_circle.setPosition(component.getX(), component.getY());
}

void GUIClient::Incantation::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_circle, states);
}
