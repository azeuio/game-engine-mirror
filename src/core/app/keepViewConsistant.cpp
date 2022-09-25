/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** keepViewConsistant
*/

#include "core/App.hpp"

void App::_keepViewConsitant(void)
{
    auto windowSize = sf::Vector2f(_window.getSize());

    _camera.setSize(windowSize);
    _display.setView(_camera);
}