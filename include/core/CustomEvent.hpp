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
        bool isPaused;
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
    Type customType = Type::Count; ///< Type of the event

    // union of all the events struct
    union {
        PauseToggleEvent pauseToggle;
    };
};
