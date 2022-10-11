/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** draw
*/

#include "core/App.hpp"

void App::draw(void)
{
    _display.clear(sf::Color::Blue);
}

void App::draw(sf::Drawable const &drawable)
{
    _display.draw(drawable);
}
