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
        DOWN = 1,
        LEFT = 2,
        UP = 3,
        RIGHT = 4
    };

    class PlayerComponent {
        public:
            struct Position {
                int x;
                int y;
                Orientation orientation;
            };

            PlayerComponent(int id) : _pos({0, 0, UP}), _id(id) {};
            PlayerComponent(int x, int y, int id) : _pos({x, y, UP}), _id(id) {};
            ~PlayerComponent() = default;

            Inventory &getInventory() { return _inventory; };
            int getX() const { return _pos.x; };
            int getY() const { return _pos.y; };
            int getLevel() const { return _level; };
            int getId() const { return _id; };

            virtual void setPos(int x, int y) { _pos = {x, y, _pos.orientation}; };
            virtual void setPos(Position pos) { _pos = pos; };
            void setLevel(int level) { _level = level; };

            void startIncantation(std::shared_ptr<Incantation> incantation) { _incantation = incantation; _isIncanting = true; };
            void stopIncantation() { _incantation = nullptr; _isIncanting = false; };
            bool isIncanting() { return _isIncanting; };
            const Incantation &getIncantation() { return *_incantation; };
        protected:
            Position _pos;
            int _level = 1;
            int _id;
            Inventory _inventory;

            std::shared_ptr<Incantation> _incantation;
            bool _isIncanting = false;
    };

    class Player : public PlayerComponent, public sf::Drawable {
        public:
            Player(int id);
            Player(int x, int y, int id);
            ~Player() = default;

            void setTeam(std::shared_ptr<Team> team);
            void setPos(int x, int y) override;
            void setPos(Position position) override;
            std::shared_ptr<Team> getTeam() { return _team; };

            sf::Text &getTextInfos() { return _textInfos; };

            void update();
            void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
        protected:
        private:
            std::shared_ptr<Team> _team;

            sf::CircleShape _playerShape;
            sf::CircleShape _directionArrow;
            sf::Text _textInfos;
            float _radius;
    };
}
