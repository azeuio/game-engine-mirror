/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** update
*/

#include "demo/Demo.hpp"

void Demo::onUpdate(void)
{
    if (isPaused()) {
        setClearColor(sf::Color::Blue);
    } else {
        setClearColor(sf::Color::Red);
    }
}