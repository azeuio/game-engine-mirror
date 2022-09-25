/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** setupDefaultListeners
*/

#include "core/App.hpp"

using Event_t = const CustomEvent &;

void App::_setupDefaultEventListeners(void)
{
    _eventManager.subscribe(sf::Event::Resized,
    [this]([[maybe_unused]]Event_t e) { this->_keepViewConsitant(); });
    _eventManager.subscribe(CustomEvent::Type::Pause,
    [this](Event_t e) { this->_isPaused = e.setPause.isPaused; });
    _eventManager.subscribe(CustomEvent::Type::Fullscreen,
    [this]([[maybe_unused]]Event_t e) { this->toggleFullscreen(); });
    _eventManager.subscribe(CustomEvent::Type::Screenshot,
    [this]([[maybe_unused]]Event_t e) { this->takeScreenshot(); });
}