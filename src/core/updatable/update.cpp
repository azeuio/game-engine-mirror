/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** update
*/

#include "core/Updatable.hpp"

void Updatable::update(void)
{
    update(_clock.getElapsedTime() - _prevTime);
}

void Updatable::update(sf::Time dt)
{
    sf::Time time = _clock.getElapsedTime();

    _dt = dt;
    _setup();
    onUpdate(_dt.asSeconds());
    _cleanup();
    _prevTime = time;
}
