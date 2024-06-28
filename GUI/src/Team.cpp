/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Team
*/

#include "Team.hpp"
#include "GUI.hpp"
#include "Map.hpp"

const std::vector<sf::Color> teamColors {
    sf::Color::Red,
    sf::Color::Green,
    sf::Color::Blue,
    sf::Color::Yellow,
    sf::Color::Magenta,
    sf::Color::Cyan,
    sf::Color::White,
    sf::Color::Black
};

GUIClient::Team::Team(std::string &name)
{
    static int colorIndex = 0;

    this->_name = name;
    this->_players = Wrappers::Players();
    this->_color = teamColors[colorIndex];
    this->_text.setString(name);
    this->_text.setColor(this->_color);
    this->_text.setCharacterSize(20);
    this->_text.setPosition(WIN_H + 10, 40 + colorIndex * 30);
    this->_text.setFont(GUI::getFont());
    colorIndex++;
}

void GUIClient::Team::addPlayer(GUIClient::Player &player)
{
    this->_players.push_back(std::make_shared<Player>(player));
}

void GUIClient::Team::removePlayer(int id)
{
    this->_players.remove(this->_players[id]);
}
