/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Tile
*/

#pragma once

#include <cstdint>
#include <SFML/Graphics.hpp>
#include "Ressources.hpp"

namespace GUIClient {
    class TileComponent {
        public:
            TileComponent(uint8_t x, uint8_t y);
            ~TileComponent() = default;

            uint8_t getX() const { return this->_x; };
            uint8_t getY() const { return this->_y; };
            void setX(const uint8_t x) { this->_x = x; };
            void setY(const uint8_t y) { this->_y = y; };
            Ressources &getContent() { return this->_content; };
            virtual void setContent(Ressources content);

        protected:
            Ressources _content;
            uint8_t _x;
            uint8_t _y;
    };

    class Tile : public sf::Drawable, public TileComponent {
        public:

            Tile(int width, int height, uint8_t x, uint8_t y);
            ~Tile() = default;

            void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
            sf::Vector2f getCenter() const { return this->_center; };
            void setContent(Ressources content) override;
        private:
            sf::Vector2f _center;
            sf::RectangleShape _shape;
            sf::RectangleShape _centerShape;
            std::vector<sf::Text> _texts;

            static const sf::Color _cellColor;
            static const sf::Color _cellOutlineColor;
    };
}