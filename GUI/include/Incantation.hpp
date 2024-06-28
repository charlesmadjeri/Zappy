/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Incantation
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace GUIClient {
    class IncantationComponent {
        public:
            IncantationComponent(int x, int y, int level) : _x(x), _y(y), _level(level) {};
            ~IncantationComponent() = default;

            int getX() const { return _x; };
            int getY() const { return _y; };
            int getLevel() const { return _level; };
        protected:
        private:
            int _x;
            int _y;
            int _level;
    };

    class Incantation : public sf::Drawable, public IncantationComponent {
        public:
            Incantation(int x, int y, int level);
            Incantation(IncantationComponent &component);

            void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
        protected:
        private:
            sf::CircleShape _circle;
    };
}
