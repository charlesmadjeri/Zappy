/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUI
*/

#include "GUI.hpp"
#include <unistd.h>
#include <sys/select.h>

std::vector<std::shared_ptr<GUIClient::Team>> GUIClient::GUI::_teams;

GUIClient::GUI::GUI()
{
    this->_window = std::make_shared<sf::RenderWindow>();
    this->_map = std::make_shared<Map>();
    this->_eventHandler = EventHandler(this->_window);
}

inline sf::Event &GUIClient::GUI::getEvent()
{
    return this->_eventHandler.getEvent();
}

void GUIClient::GUI::addTeam(std::string &name)
{
    for (std::shared_ptr<Team> team : this->_teams) {
        if (team->getName() == name) {
            std::cerr << "Team " << name << " already exists." << std::endl;
            return;
        }
    }
    this->_teams.push_back(std::make_shared<Team>(name));
}

GUIClient::Player &GUIClient::GUI::getPlayer(int id)
{
    return *this->_players[id];
}

void GUIClient::GUI::removePlayer(int id)
{
    this->_players[id]->getTeam()->removePlayer(id);
    this->_players.remove(this->_players[id]);
}

void GUIClient::GUI::startIncantation(IncantationComponent incantation, std::vector<int> playerIDs)
{
    std::shared_ptr<Incantation> incantationPtr = std::make_shared<Incantation>(incantation);

    for (int id : playerIDs) {
        std::shared_ptr<Player> player = this->_players[id];
        player->startIncantation(incantationPtr);
    }
}

void GUIClient::GUI::stopIncantation(IncantationComponent incantation)
{
    for (std::shared_ptr<Player> player : this->_players) {
        if (player->isIncanting() &&
            player->getIncantation().getX() == incantation.getX() &&
            player->getIncantation().getY() == incantation.getY() &&
            player->getIncantation().getLevel() == incantation.getLevel()) {
                player->stopIncantation();
            }
    }
}

void GUIClient::GUI::run()
{
    Communication &comm = this->getCommunication();
    this->_window->create(sf::VideoMode(WIN_W, WIN_H), "Zappy GUI");

    while (this->_window->isOpen()) {
        comm.handleCommunications(*this);
        if (this->_eventHandler.pollEvents() == -1)
            break;
        this->_window->draw(*this->_map);
        this->_window->display();
        this->_window->clear();
    }
}
