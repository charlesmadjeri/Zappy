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

#define FONT_PATH   "../assets/font.ttf"
#define WIN_H       600
#define WIN_W       800

namespace GUIClient {
    class GUI {
        public:
            GUI();
            ~GUI() = default;

            void run();
            void startIncantation(IncantationComponent incantation, std::vector<int> playerIDs);
            void stopIncantation(IncantationComponent Incantation);

            sf::RenderWindow &getWindow() const { return *_window; }
            sf::Event &getEvent();
            Communication &getCommunication() { return _communication; }
            Map &getMap() { return *_map; }
            static std::vector<std::shared_ptr<Team>> &getTeams() { return _teams; }
            Player &getPlayer(int id);

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
    };
}
