/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Player
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Inventory.hpp"

namespace GUIClient {
    class Player {
        public:
            Player(int x, int y, int id): _x(x), _y(y), _id(id) {};
            ~Player() = default;

            Inventory &getInventoryFromServer();
            Inventory &getInventory();

            int getX() const;
            int getY() const;
            sf::Vector2f getPos() const;

            int getLevel() const;
            int getId() const;
        protected:
        private:
            int _x;
            int _y;
            int _level = 1;
            int _id;
            Inventory _inventory;
    };
}
