/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** pollEvent
*/

#include "core/App.hpp"

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
        sf::View view = _display.getView();
        _width = event.size.width;
        _height = event.size.height;
        view.setSize((float)_width, (float)_height);
        _display.setView(view);
    }
    return true;
}
