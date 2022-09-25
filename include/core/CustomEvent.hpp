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
    struct PauseSetEvent {
        bool isPaused;
    };

    struct FullscreenSetEvent {
        bool isFullscreenOn;
    };

    CustomEvent(void) = default;
    explicit CustomEvent(sf::Event const &event) : sf::Event(event) {};

    ////////////////////////////////////////////////////////////
    /// \brief Enumeration of the different types of events
    ///
    ////////////////////////////////////////////////////////////
    enum class Type
    {
        Pause,  //< The window requested to be (un)paused
        Fullscreen, //< The window requested to set fullscreen status
        Screenshot, //< A screenshot is being taken

        Count   //< Keep last -- the total number of event types
    };

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    Type customType = Type::Count; //< Type of the event

    // union of all the events struct
    union {
        PauseSetEvent setPause;
        FullscreenSetEvent setFullscreen;
    };
};
