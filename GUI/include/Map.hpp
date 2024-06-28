/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Map
*/

#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Tile.hpp"

namespace GUIClient {
    class Map : public sf::Drawable {
        public:
            Map() = default;
            Map(uint width, uint height);
            ~Map() = default;

            void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
            void create(sf::Vector2i size);
            void create(uint width, uint height);
            Tile &getTile(uint8_t x, uint8_t y) { return _tiles[x + y * _width]; }
            void setTile(TileComponent component);
            static uint getWidth() { return _width; }
            static uint getHeight() { return _height; }
        protected:
        private:
            static uint _width;
            static uint _height;
            std::vector<Tile> _tiles;
    };
}
