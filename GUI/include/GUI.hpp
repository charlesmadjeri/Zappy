/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUI
*/

#pragma once

#include <memory>
#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "EventHandler.hpp"
#include "Communication.hpp"
#include "Team.hpp"
#include "Incantation.hpp"
#include "Wrappers.hpp"
#include "macros.hpp"

namespace GUIClient {
    enum class TextType {
        TEAMS_TITLE,
        RESSOURCES_TITLE,
        PLAYERS_TITLE,
        FOOD,
        LINEMATE,
        DERAUMERE,
        SIBUR,
        MENDIANE,
        PHIRAS,
        THYSTANE
    };

    class GUI {
        public:
            GUI();
            ~GUI() = default;

            void run();
            void writeServerMessage(std::string &msg) {};
            void startIncantation(IncantationComponent incantation, std::vector<int> playerIDs);
            void stopIncantation(IncantationComponent Incantation);

            sf::RenderWindow &getWindow() const { return *_window; }
            sf::Event &getEvent();
            Communication &getCommunication() { return _communication; }
            Map &getMap() { return *_map; }
            static std::vector<std::shared_ptr<Team>> &getTeams() { return _teams; }
            Player &getPlayer(int id);
            static const sf::Font &getFont();

            void addTeam(std::string &name);
            void addPlayer(Player player) { _players.push_back(std::make_shared<Player>(player)); }

            void removePlayer(int id);
        protected:
        private:
            std::shared_ptr<sf::RenderWindow> _window;
            EventHandler _eventHandler;
            Communication _communication;
            std::shared_ptr<Map> _map;
            Wrappers::Players _players;
            static std::vector<std::shared_ptr<Team>> _teams;
            static sf::Font _font;
            std::map<TextType, sf::Text> _texts;

            void _initTexts();
    };
}
