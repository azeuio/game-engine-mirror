/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** EventManager
*/

#pragma once

#include <vector>
#include <array>
#include <functional>

#include "core/CustomEvent.hpp"

class EventManager {
private:
    struct EventListenerData {
        unsigned int id;
        std::function<void(CustomEvent const &)> const& callback;
        bool isCustom;
    };
    // std::array<
    // std::vector<struct EventListenerData const&>,
    // ((int)CustomEvent::Count + (int)CustomEvent::Type::Count)
    // > _listeners;
public:
    void broadcast(CustomEvent const &event);


    /**
     * @brief Makes `manager` call `onEvent` when `event` is broadcasted.
     * @param type The type of the event to listen to.
     * @param callback The callback to call when the event is broadcasted.
     * @param isCustom Whether the event is a custom event or a sfml event.
     * @return index of the listener in the list of listeners
     */
    int subscribe(CustomEvent::Type type,
    std::function<void(CustomEvent const &)> const& callback,
    bool isCustom = false);

    /**
     * @brief Makes `manager` stop calling `onEvent` when `event`
     * is broadcasted.
     * @param type The type of the event to stop listening to.
     * @param manager The manager to unregister from.
     */
    void unsubscribe(CustomEvent::Type type, int id);
};
