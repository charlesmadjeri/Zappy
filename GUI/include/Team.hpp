/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Team
*/

#pragma once

#include <vector>
#include <memory>
#include "Player.hpp"
#include "Wrappers.hpp"

namespace GUIClient {
    class Team {
        public:
            Team(std::string &name);
            ~Team() = default;

            std::string &getName() { return _name; }
            Wrappers::Players &getPlayers() { return _players; }

            void addPlayer(Player &player);
            void removePlayer(int id);
        protected:
        private:
            Wrappers::Players _players;
            std::string _name;
    };
}
