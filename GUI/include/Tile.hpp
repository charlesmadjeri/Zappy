/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Tile
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace GUIClient {
    class Tile : public sf::Drawable {
        public:
            Tile(int width, int height, float x, float y);
            ~Tile() = default;

            void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        protected:
        private:
            sf::Vector2f _center;
            sf::RectangleShape _shape;
            sf::RectangleShape _centerShape;

            static const sf::Color _cellColor;
            static const sf::Color _cellOutlineColor;
    };
}