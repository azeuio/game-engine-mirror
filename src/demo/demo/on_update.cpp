/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** update
*/

#include "demo/Demo.hpp"

void Demo::onUpdate(sf::Time dt)
{
    if (isPaused()) {
        setClearColor(sf::Color::Blue);
    } else {
        setClearColor(sf::Color::Red);
    }
    getCamera().move(dt.asSeconds(), 0);
}
