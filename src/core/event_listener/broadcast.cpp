/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** broadcast
*/

#include "core/EventManager.hpp"

void EventManager::broadcast(CustomEvent const& event)
{
    if (event.type != sf::Event::Count) {
        for (EventListenerData listener : getListener(event.type)) {
            listener.callback(event);
        }
        return;
    }
    if (event.customType != CustomEvent::Type::Count) {
        for (EventListenerData listener : getListener(event.customType)) {
            listener.callback(event);
        }
        return;
    }
}