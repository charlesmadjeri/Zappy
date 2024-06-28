/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Tile
*/

#include "Debug.hpp"
#include "GUI.hpp"
#include "Tile.hpp"

// const sf::Color GUIClient::Tile::_cellColor = sf::Color(255, 255, 255);
const sf::Color GUIClient::Tile::_cellColor = sf::Color(64, 128, 128);
const sf::Color GUIClient::Tile::_cellOutlineColor = sf::Color(192, 192, 96);

GUIClient::TileComponent::TileComponent(uint8_t x, uint8_t y)
{
    this->_x = x;
    this->_y = y;
}

void GUIClient::TileComponent::setContent(GUIClient::Ressources content)
{
    this->_content = content;
}

GUIClient::Tile::Tile(int width, int height, uint8_t x, uint8_t y) : TileComponent(x, y)
{
    this->_center = sf::Vector2f(x * width * 1.5, y * height * 1.5);
    this->_shape = sf::RectangleShape(sf::Vector2f(width, height));
    this->_shape.setFillColor(this->_cellColor);
    this->_shape.setOutlineColor(this->_cellOutlineColor);
    this->_shape.setOutlineThickness(-2);
    this->_shape.setPosition(x * width, y * height);

    if (DEBUG) {
        this->_centerShape = sf::RectangleShape(sf::Vector2f(width / 10, height / 10));
        this->_centerShape.setFillColor(this->_cellOutlineColor);
        this->_centerShape.setPosition(this->_center.x - width / 20, this->_center.y - height / 20);
    }

    Ressources &ressources = this->getContent();
    std::vector<sf::Color> colors = {
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::Yellow,
        sf::Color::Magenta,
        sf::Color::Cyan,
        sf::Color::White
    };

    for (int i = 0; i < 7; i++) {
        sf::Text text(std::to_string(ressources.getRessource(static_cast<RessourceID>(i))), GUI::getFont(), 12);
        text.setPosition(this->_shape.getPosition().x + 2, this->_shape.getPosition().y + 2 + i * 10);
        text.setFillColor(colors[i]);
        this->_texts.push_back(text);
    }
}

void GUIClient::Tile::setContent(GUIClient::Ressources content)
{
    TileComponent::setContent(content);

    for (int i = 0; i < 7; i++) {
        sf::Text &text = this->_texts[i];
        text.setString(std::to_string(content.getRessource(static_cast<RessourceID>(i))));
    }
}

void GUIClient::Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->_shape, states);

    if (DEBUG)
        target.draw(this->_centerShape, states);

    for (auto &text : this->_texts)
        target.draw(text, states);
}

