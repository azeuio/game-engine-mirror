/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** toggleFullscreen
*/

#include "core/App.hpp"

void App::toggleFullscreen(void)
{
    if (_isFullscreen) {
        _window.create(sf::VideoMode(_width, _height), _title,
        sf::Style::Default);
        _isFullscreen = false;
        return;
    }
    _window.create(sf::VideoMode::getDesktopMode(), _title,
    sf::Style::Fullscreen);
    _isFullscreen = true;
}
