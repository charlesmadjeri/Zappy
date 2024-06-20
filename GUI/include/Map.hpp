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
            Map(uint width, uint height);
            ~Map() = default;

            void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        protected:
        private:
            uint _width;
            uint _height;
            std::vector<Tile> _tiles;
    };
}
