/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** draw
*/

#include "core/App.hpp"

void App::draw(void)
{
    _display.clear(_clearColor);
    _window.clear(_clearColor);
}

void App::draw(sf::Drawable const &drawable)
{
    _display.draw(drawable);
}
