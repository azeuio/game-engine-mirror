/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** CustomEvent
*/

#pragma once

#include <SFML/Window/Event.hpp>

class CustomEvent : public sf::Event {
    public:

    ////////////////////////////////////////////////////////////
    /// \brief Enumeration of the different types of events
    ///
    ////////////////////////////////////////////////////////////
    enum CustomEventType
    {
        Count                   ///< Keep last -- the total number of event types
    };

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    EventType customType; ///< Type of the event

    // union of all the events struct
    #if 0
    // union
    // {
    // };
    #endif
};
