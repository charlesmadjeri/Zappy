/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Ressources
*/

#include "Ressources.hpp"

GUIClient::Ressources::Ressources(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame)
{
    this->food = food;
    this->linemate = linemate;
    this->deraumere = deraumere;
    this->sibur = sibur;
    this->mendiane = mendiane;
    this->phiras = phiras;
    this->thystame = thystame;
}

int &GUIClient::Ressources::getRessource(RessourceID ressourceId)
{
    switch (ressourceId) {
        case RessourceID::FOOD:
            return this->food;
        case RessourceID::LINEMATE:
            return this->linemate;
        case RessourceID::DERAUMERE:
            return this->deraumere;
        case RessourceID::SIBUR:
            return this->sibur;
        case RessourceID::MENDIANE:
            return this->mendiane;
        case RessourceID::PHIRAS:
            return this->phiras;
        case RessourceID::THYSTAME:
            return this->thystame;
    }
    return this->food;
}

void GUIClient::Ressources::addRessource(RessourceID ressourceId)
{
    this->getRessource(ressourceId)++;
}

void GUIClient::Ressources::removeRessource(RessourceID ressourceId)
{
    this->getRessource(ressourceId)--;
}
