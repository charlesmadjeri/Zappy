/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Player
*/

#include <iostream>
#include <sstream>
#include "Player.hpp"
#include "Team.hpp"
#include "Map.hpp"
#include "GUI.hpp"

GUIClient::Player::Player(int id) : Player(0, 0, id) {}

GUIClient::Player::Player(int x, int y, int id) : PlayerComponent(x, y, id)
{
    std::stringstream ss;
    uint tileWidth = WIN_H / Map::getWidth();
    uint tileHeight = WIN_H / Map::getHeight();
    float longestTileSide = tileWidth > tileHeight ? tileWidth : tileHeight;
    float radius = longestTileSide / 2 * 0.6;

    this->_playerShape.setRadius(radius);
    this->_playerShape.setOrigin(radius, radius);
    this->_playerShape.setPosition(x * tileWidth * 1.5, y * tileHeight * 1.5);
    this->_directionArrow.setPointCount(3);
    this->_directionArrow.setRadius(radius * 0.6);
    this->_directionArrow.setOrigin(radius * 0.6, radius * 0.6);
    this->_directionArrow.setFillColor(sf::Color::Black);
    this->_directionArrow.setOutlineColor(sf::Color::White);
    this->_directionArrow.setOutlineThickness(-1);
    this->_directionArrow.setPosition(this->_playerShape.getPosition());
    this->_directionArrow.setRotation(90 * (this->_pos.orientation - 1));

    this->_textInfos.setFont(GUI::getFont());
    this->_textInfos.setCharacterSize(20);
    this->_textInfos.setPosition(WIN_H + 10, WIN_H / 3 + 25);
}

void GUIClient::Player::setTeam(std::shared_ptr<Team> team)
{
    this->_team = team;
    this->_team->addPlayer(*this);
    this->_playerShape.setFillColor(this->_team->getColor());
    this->_textInfos.setFillColor(this->_team->getColor());
}

void GUIClient::Player::setPos(int x, int y)
{
    this->setPos({x, y, this->_pos.orientation});
}

void GUIClient::Player::setPos(Position pos)
{
    PlayerComponent::setPos(pos);

    uint tileWidth = WIN_H / GUIClient::Map::getWidth();
    uint tileHeight = WIN_H / GUIClient::Map::getHeight();

    this->_playerShape.setPosition(tileWidth * (this->_pos.x + 0.5), tileHeight * (this->_pos.y + 0.5));
    this->_directionArrow.setPosition(this->_playerShape.getPosition());
    this->_directionArrow.setRotation(90 * (this->_pos.orientation - 1));
}

void GUIClient::Player::update()
{
    std::stringstream ss;
    Ressources &content = this->_inventory.getContent();

    ss  << "Player " << this->_id << " (" << this->_level << ") [x: " << this->_pos.x << ", y: " << this->_pos.y << "] {";

    for (int i = 0; i < 7; i++) {
        ss << " " << content.getRessource(static_cast<RessourceID>(i));
    }
    ss << " }";

    this->_textInfos.setString(ss.str());
}

void GUIClient::Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_playerShape, states);
    target.draw(this->_directionArrow, states);
    target.draw(this->_textInfos, states);
}
