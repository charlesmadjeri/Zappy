/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Tile
*/

#include "Debug.hpp"
#include "Tile.hpp"

const sf::Color GUIClient::Tile::_cellColor = sf::Color::White;
const sf::Color GUIClient::Tile::_cellOutlineColor = sf::Color::Green;

GUIClient::TileComponent::TileComponent(uint8_t x, uint8_t y)
{
    this->_x = x;
    this->_y = y;
    this->_content = {0, 0, 0, 0, 0, 0, 0};
}

void GUIClient::TileComponent::setContent(GUIClient::Ressources content)
{
    this->_content = content;
}

GUIClient::Tile::Tile(int width, int height, uint8_t x, uint8_t y) : TileComponent(x, y)
{
    this->_center = sf::Vector2f(x * width * 1.5, y * height * 1.5);
    this->_shape = sf::RectangleShape(sf::Vector2f(width, height));
    this->_shape.setFillColor(this->_cellColor);
    this->_shape.setOutlineColor(this->_cellOutlineColor);
    this->_shape.setOutlineThickness(-2);
    this->_shape.setPosition(x * width, y * height);

    if (DEBUG) {
        this->_centerShape = sf::RectangleShape(sf::Vector2f(width / 10, height / 10));
        this->_centerShape.setFillColor(this->_cellOutlineColor);
        this->_centerShape.setPosition(this->_center.x - width / 20, this->_center.y - height / 20);
    }
}

void GUIClient::Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->_shape, states);

    if (DEBUG)
        target.draw(this->_centerShape, states);
}

