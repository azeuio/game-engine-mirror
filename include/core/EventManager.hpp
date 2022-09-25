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
public:
    struct EventListenerData {
        unsigned int id;
        std::function<void (const CustomEvent &)> callback;
        bool isCustom;
    };
private:
    std::vector<
    std::vector<struct EventListenerData>> _listeners;
public:
    EventManager(void) {
        int nbListenerType = (
        (int)CustomEvent::Type::Count + (int)sf::Event::Count + 2);

        for (int i = 0; i < nbListenerType; i++) {
            _listeners.emplace_back(
            std::vector<EventManager::EventListenerData>()
            );
        }
    }
    std::vector<struct EventListenerData> &getListener(
    CustomEvent::Type type)
    {
        static std::size_t nbSfEvent = sf::Event::Count;

        return _listeners[nbSfEvent + (std::size_t)type];
    }
    std::vector<struct EventListenerData> &getListener(
    sf::Event::EventType type) { return _listeners.at((std::size_t)type); }

    /**
     * @brief Use callback function of every concerned listener of this
     * particular event
     * @param event Event to broadcast
     */
    void broadcast(CustomEvent const &event);

    /**
     * @brief Adds callback to the list of function called when `event` is
     * broadcasted.
     * @param type The type of the event to listen to.
     * @param callback The callback to call when the event is broadcasted.
     * @param isCustom Whether the event is a custom event or a sfml event.
     * @return index of the listener in the list of listeners
     */
    int subscribe(CustomEvent::Type type,
    std::function<void (const CustomEvent &)> const& callback);
    /**
     * @brief Adds callback to the list of function called when `event` is
     * broadcasted.
     * @param type The type of the event to listen to.
     * @param callback The callback to call when the event is broadcasted.
     * @param isCustom Whether the event is a custom event or a sfml event.
     * @return index of the listener in the list of listeners
     */
    int subscribe(sf::Event::EventType type,
    std::function<void (const CustomEvent &)> const& callback);

    /**
     * @brief Makes `manager` stop calling `onEvent` when `event`
     * is broadcasted.
     * @param type The type of the event to stop listening to.
     * @param manager The manager to unregister from.
     */
    void unsubscribe(CustomEvent::Type type, int id);
};
