/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** onUpdate
*/

#include "demo/BugWalker.hpp"

void BugWalker::onUpdate(sf::Time dt)
{
    Entity::onUpdate(dt);
    move(0.1f, 0);
}
