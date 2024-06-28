/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Map
*/

#include "GUI.hpp"
#include "Map.hpp"
#include <SFML/Graphics.hpp>

uint GUIClient::Map::_width = 30;
uint GUIClient::Map::_height = 30;

GUIClient::Map::Map(uint width, uint height)
{
    this->create(width, height);
}

void GUIClient::Map::create(const sf::Vector2i size)
{
    this->create(size.x, size.y);
}

void GUIClient::Map::create(uint width, uint height)
{
    this->_width = width;
    this->_height = height;
    this->_tiles.clear();

    float tileHeight = WIN_H / height;
    float tileWidth = WIN_H / width;

    for (uint i = 0; i < width; i++) {
        for (uint j = 0; j < height; j++) {
            Tile tile(tileWidth, tileHeight, i, j);
            this->_tiles.push_back(tile);
        }
    }
}

void GUIClient::Map::setTile(GUIClient::TileComponent component)
{
    this->_tiles[component.getX() + component.getY() * this->_width].setContent(component.getContent());
}

void GUIClient::Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (Tile tile : this->_tiles) {
        target.draw(tile, states);
    }
}
