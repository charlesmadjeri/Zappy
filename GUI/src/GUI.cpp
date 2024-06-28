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
sf::Font GUIClient::GUI::_font = sf::Font();

void GUIClient::GUI::_initTexts()
{
    std::vector<std::tuple<TextType, std::string, sf::Vector2f, sf::Color>> textData = {
        {TextType::TEAMS_TITLE, "Teams:", {WIN_H + 10, 10}, sf::Color::White},
        {TextType::RESSOURCES_TITLE, "Ressources:", {WIN_H + 150, 10}, sf::Color::White},
        {TextType::PLAYERS_TITLE, "Players:", {WIN_H + 10, WIN_H / 3}, sf::Color::White},
        {TextType::FOOD, "Food", {WIN_H + 150, 35}, sf::Color::Red},
        {TextType::LINEMATE, "Linemate", {WIN_H + 150, 60}, sf::Color::Green},
        {TextType::DERAUMERE, "Deraumere", {WIN_H + 150, 85}, sf::Color::Blue},
        {TextType::SIBUR, "Sibur", {WIN_H + 150, 110}, sf::Color::Yellow},
        {TextType::MENDIANE, "Mendiane", {WIN_H + 150, 135}, sf::Color::Magenta},
        {TextType::PHIRAS, "Phiras", {WIN_H + 150, 160}, sf::Color::Cyan},
        {TextType::THYSTANE, "Thystane", {WIN_H + 150, 185}, sf::Color::White},
    };

    for (auto textElement : textData) {
        TextType &type = std::get<0>(textElement);
        std::string &text = std::get<1>(textElement);
        sf::Vector2f &position = std::get<2>(textElement);
        sf::Color &color = std::get<3>(textElement);
        this->_texts[type] = sf::Text(text, GUI::getFont(), 20);
        this->_texts[type].setPosition(position);
        this->_texts[type].setColor(color);
    }
}

GUIClient::GUI::GUI()
{
    this->_window = std::make_shared<sf::RenderWindow>();
    this->_map = std::make_shared<Map>();
    this->_eventHandler = EventHandler(this->_window);
    this->_font.loadFromFile(FONT_PATH);
    this->_initTexts();
}

const sf::Font &GUIClient::GUI::getFont()
{
    return GUIClient::GUI::_font;
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
        this->_players.updatePlayerTextInfos();
        for (std::shared_ptr<Player> player : this->_players)
            this->_window->draw(*player);
        for (auto textElement : this->_texts)
            this->_window->draw(textElement.second);
        for (std::shared_ptr<Team> team : this->_teams)
            this->_window->draw(team->getText());
        this->_window->display();
        this->_window->clear();
    }
}
