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
        _window.create(sf::VideoMode(_width, _height), _title, sf::Style::Default);
        _isFullscreen = false;
    } else {
        _window.create(sf::VideoMode(0, 0), _title, sf::Style::Fullscreen);
        _isFullscreen = true;
    }
}
