/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TileContent
*/

#pragma once

class TileContent {
    public:
        TileContent(int food = 0, int linemate = 0, int deraumere = 0, int sibur = 0, int mendiane = 0, int phiras = 0, int thystame = 0) : _food(food), _linemate(linemate), _deraumere(deraumere), _sibur(sibur), _mendiane(mendiane), _phiras(phiras), _thystame(thystame) {};
        ~TileContent() = default;

    protected:
    private:
        int _food;
        int _linemate;
        int _deraumere;
        int _sibur;
        int _mendiane;
        int _phiras;
        int _thystame;
};
