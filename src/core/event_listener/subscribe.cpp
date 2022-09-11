/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** subscribe
*/

#include "core/EventManager.hpp"

int EventManager::subscribe(CustomEvent::Type type,
std::function<void(CustomEvent const &)> const& callback,
bool isCustom)
{
    static unsigned int id = 0;
    struct EventListenerData data = {id, callback, isCustom};

    if (type == CustomEvent::Type::Count)
        return -1;
    this->_listeners[(int)type].push_back(data);
    return data.id;
}
