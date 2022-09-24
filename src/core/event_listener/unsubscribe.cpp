/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** unsubscribe
*/

#include <vector>

#include "core/EventManager.hpp"

void EventManager::unsubscribe(CustomEvent::Type type, int id)
{
    throw std::logic_error("Not implemented yet");
    // std::vector<EventManager::EventListenerData> a;
    // if (type == CustomEvent::Type::Count || id == -1)
    //     return;
    // printf("unsubscribing\n");
    // // for (auto it = this->_listeners[(int)type].begin();
    // // it != this->_listeners[(int)type].end(); it++) {
    // //     if (it->id == id) {
    // //         this->_listeners.at((int)type).erase(it);
    // //     }
    // // }
}
