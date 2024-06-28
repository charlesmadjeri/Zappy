/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** operators
*/

#pragma once

#include <vector>
#include <iostream>

std::vector<std::string> splitString(std::string str, const char delim = ' ', bool keepDelim = false);
inline int getNumber(const std::string &str) { return std::stoi(str, nullptr, 10); };

template <typename T>
std::vector<T> &operator+(std::vector<T> &vec, int offset)
{
    vec.erase(vec.begin(), vec.begin() + offset);
    return vec;
}
