/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Map
*/

#include "GUI.hpp"
#include "Map.hpp"
#include <SFML/Graphics.hpp>

GUIClient::Map::Map(uint width, uint height)
{
    this->_width = width;
    this->_height = height;
    this->_tiles = std::vector<Tile>();

    float tileHeight = WIN_H / height;
    float tileWidth = WIN_H / width;

    for (uint i = 0; i < width; i++) {
        for (uint j = 0; j < height; j++) {
            Tile tile(tileWidth, tileHeight, i * tileWidth, j * tileHeight);
            this->_tiles.push_back(tile);
        }
    }
}

void GUIClient::Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (Tile tile : this->_tiles) {
        target.draw(tile, states);
    }
}
