/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Wrappers
*/

#pragma once

#include <list>
#include <memory>

namespace GUIClient {
    class Player;
}

namespace Wrappers {
    class Players : public std::list<std::shared_ptr<GUIClient::Player>> {
        public:
            std::shared_ptr<GUIClient::Player> &operator[](std::size_t idx);
            void updatePlayerTextInfos();
    };
}