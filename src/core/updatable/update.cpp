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
    _prevTime = _clock.getElapsedTime();

    _dt = dt;
    this->_setup();
    this->onUpdate(_dt);
    this->_cleanup();
}
