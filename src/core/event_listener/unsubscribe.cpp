/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** unsubscribe
*/

#include "core/EventManager.hpp"

void EventManager::unsubscribe(CustomEvent::Type type, int id)
{
    if (type == CustomEvent::Type::Count || id == -1)
        return;
    for (auto it = this->_listeners[(int)type].begin();
    it != this->_listeners[(int)type].end(); it++) {
        if (it->id == id) {
            this->_listeners[(int)type].erase(it);
            return;
        }
    }
}
