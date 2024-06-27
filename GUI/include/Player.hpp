/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Player
*/

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "Inventory.hpp"
#include "Incantation.hpp"

namespace GUIClient {
    class Team;

    enum Orientation {
        UP = 1,
        RIGHT = 2,
        DOWN = 3,
        LEFT = 4
    };

    class Player {
        public:
            struct Position {
                int x;
                int y;
                Orientation orientation;
            };

            Player(int id) : _pos({0, 0, UP}), _id(id) {};
            Player(int x, int y, int id) : _pos({x, y, UP}), _id(id) {};
            ~Player() = default;

            Inventory &getInventory() { return _inventory; };
            int getX() const { return _pos.x; };
            int getY() const { return _pos.y; };
            sf::Vector2f getPos() const { return sf::Vector2f(_pos.x, _pos.y); };
            int getLevel() const { return _level; };
            std::shared_ptr<Team> getTeam() { return _team; };
            int getId() const { return _id; };

            void setPos(int x, int y) { _pos = {x, y, _pos.orientation}; };
            void setPos(int x, int y, Orientation orientation) { _pos = {x, y, orientation}; };
            void setPos(Position pos) { _pos = pos; };
            void setLevel(int level) { _level = level; };
            void setTeam(std::shared_ptr<Team> team);

            void startIncantation(std::shared_ptr<Incantation> incantation) { _incantation = incantation; _isIncanting = true; };
            void stopIncantation() { _incantation = nullptr; _isIncanting = false; };
            bool isIncanting() { return _isIncanting; };
            const Incantation &getIncantation() { return *_incantation; };
        protected:
        private:
            Position _pos;
            int _level = 1;
            int _id;
            Inventory _inventory;
            std::shared_ptr<Team> _team;

            std::shared_ptr<Incantation> _incantation;
            bool _isIncanting = false;
    };
}
