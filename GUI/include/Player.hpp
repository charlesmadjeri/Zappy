/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Player
*/

#pragma once

#include "Inventory.hpp"

namespace GUI {
    class Player {
        public:
            Player(int x, int y, int id);
            ~Player();

            Inventory getInventoryFromServer();
        protected:
        private:
            int _x;
            int _y;
            int _level;
            int _id;
    };
}
