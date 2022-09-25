/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** subscribe
*/

#include "core/EventManager.hpp"

static unsigned int id;

int EventManager::subscribe(CustomEvent::Type type,
std::function<void (const CustomEvent &)> const& callback)
{
    struct EventListenerData data = {
        id, callback, true};
    static std::size_t nbSfEventType = sf::Event::Count;

    id++;
    if (type == CustomEvent::Type::Count)
        return -1;
    this->_listeners.at((std::size_t)type + nbSfEventType).push_back(data);
    return data.id;
}

int EventManager::subscribe(sf::Event::EventType type,
std::function<void (const CustomEvent &)> const& callback)
{
    struct EventListenerData data = {
        id, callback, false};

    id++;
    if (type == sf::Event::EventType::Count)
        return -1;
    this->_listeners.at((std::size_t)type).push_back(data);
    return data.id;
}