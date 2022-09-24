/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** broadcast
*/

#include "core/EventManager.hpp"

void EventManager::broadcast(CustomEvent const& event)
{
    static int a;
    if (event.type != sf::Event::Count) {
        for (EventListenerData listener : getListener(event.type)) {
            listener.callback(event);
        }
    } else if (event.customType != CustomEvent::Type::Count) {
        for (EventListenerData listener : getListener(event.customType)) {
            printf("callback for id:%d\n", listener.id);
            listener.callback(event);
        }
    }
}