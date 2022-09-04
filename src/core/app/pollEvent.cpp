/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** pollEvent
*/

#include "core/App.hpp"

bool App::pollEvent(CustomEvent &event)
{
    // TODO: add event listener
    bool result = _window.pollEvent(event);

    if (result == false)
        return false;
    if (event.type == sf::Event::Closed)
        stop();
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == keybindings.pause)
            _isPaused = !_isPaused;
        if (event.key.code == keybindings.fullscreen)
            toggleFullscreen();
        if (event.key.code == keybindings.screenshot)
            takeScreenshot();
    }
    return true;
}
