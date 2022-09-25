/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** toggleFullscreen
*/

#include "core/App.hpp"

void App::toggleFullscreen(void)
{
    static unsigned int prev_width;
    static unsigned int prev_height;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    if (_isFullscreen) {
        // _window.create(sf::VideoMode(prev_width, prev_height), _title,
        // sf::Style::Default);
        // centerWindow();
        _isFullscreen = false;
        _recreateWindow(prev_width, prev_height);
        _keepViewConsitant();
        _width = prev_width;
        _height = prev_height;
        return;
    }
    prev_width = _width;
    prev_height = _height;
    _width = desktop.width;
    _height = desktop.height;
    // _window.create(desktop, _title,
    // sf::Style::Fullscreen);
    _recreateWindow(desktop.width, desktop.height, sf::Style::Fullscreen);
    _isFullscreen = true;
    _keepViewConsitant();
}
