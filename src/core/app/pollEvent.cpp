/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** pollEvent
*/

#include "core/App.hpp"

void App::_keepViewConsitant(void)
{
    auto windowSize = sf::Vector2f(_window.getSize());

    _camera.setSize(windowSize);
    _display.setView(_camera);
}

bool App::pollEvent(CustomEvent &event)
{
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
    if (event.type == sf::Event::Resized) {
        _keepViewConsitant();
    }
    return true;
}
