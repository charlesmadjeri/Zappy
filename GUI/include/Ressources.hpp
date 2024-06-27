/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Ressources
*/

#pragma once

namespace GUIClient {
    enum RessourceID {
        FOOD = 0,
        LINEMATE = 1,
        DERAUMERE = 2,
        SIBUR = 3,
        MENDIANE = 4,
        PHIRAS = 5,
        THYSTAME = 6
    };

    class Ressources {
        public:
            Ressources(int food = 0, int linemate = 0, int deraumere = 0, int sibur = 0, int mendiane = 0, int phiras = 0, int thystame = 0);
            ~Ressources() = default;

            int &getRessource(RessourceID ressourceId);
            void addRessource(RessourceID ressourceId);
            void removeRessource(RessourceID ressourceId);

            int food;
            int linemate;
            int deraumere;
            int sibur;
            int mendiane;
            int phiras;
            int thystame;
    };
}
