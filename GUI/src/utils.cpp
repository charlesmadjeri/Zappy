/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** operators
*/

#include "utils.hpp"

std::vector<std::string> splitString(std::string str, const char delim, bool keepDelim)
{
    std::vector<std::string> result;
    std::string tmp;

    while (str.find(delim) != std::string::npos) {
        tmp = str.substr(0, str.find(delim));
        if (keepDelim)
            tmp += delim;
        result.push_back(tmp);
        str = str.substr(str.find(delim) + 1);
    }
    result.push_back(str);

    return result;
}

template <typename T>
std::vector<T> &operator+(std::vector<T> &vec, int offset)
{
    return vec.erase(vec.begin(), vec.begin() + offset);
}
