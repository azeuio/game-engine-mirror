/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** setupDefaultListeners
*/

#include "core/App.hpp"

typedef const CustomEvent & Event_t;

void App::_setupDefaultEventListeners(void)
{
    _eventManager.subscribe(sf::Event::Resized,
    [&]([[maybe_unused]]Event_t e) { this->_keepViewConsitant(); });
    _eventManager.subscribe(CustomEvent::Type::Pause,
    [&](Event_t e) { this->_isPaused = e.setPause.isPaused; });
    _eventManager.subscribe(CustomEvent::Type::Fullscreen,
    [&]([[maybe_unused]]Event_t e) { this->toggleFullscreen(); });
    _eventManager.subscribe(CustomEvent::Type::Screenshot,
    [&]([[maybe_unused]]Event_t e) { this->takeScreenshot(); });
}