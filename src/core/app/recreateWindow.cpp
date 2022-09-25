/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** recreateWindow
*/

#include "core/App.hpp"

void App::_recreateWindow(unsigned int width, unsigned int height,
sf::Uint32 style)
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    _width = width;
    _height = height;
    _window.create(sf::VideoMode(desktop.width, desktop.height), _title,
    style);
    _window.setSize({_width, _height});
    setFPS(_fps);
    centerWindow();
}