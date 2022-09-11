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
    struct PauseToggleEvent {
        int desiredState; /// <0 = pause, >0 = unpause, 0 = toggle
    };
    CustomEvent(void) = default;
    CustomEvent(sf::Event const &event) : sf::Event(event) {};

    ////////////////////////////////////////////////////////////
    /// \brief Enumeration of the different types of events
    ///
    ////////////////////////////////////////////////////////////
    enum class Type
    {
        Pause,  ///< The window requested to be paused
        Count   ///< Keep last -- the total number of event types
    };

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    Type customType; ///< Type of the event

    // union of all the events struct
    union {
        PauseToggleEvent pauseToggle;
    };
};
