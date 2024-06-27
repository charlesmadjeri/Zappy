/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Inventory
*/

#pragma once

#include "Tile.hpp"

namespace GUIClient {
    class Inventory {
        public:
            Inventory();
            ~Inventory();

            void setContent(Ressources ressources) { _ressources = ressources; };
            Ressources &getContent() { return _ressources; };
        protected:
        private:
            Ressources _ressources;
    };
}
