/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** onUpdate
*/

#include "core/Entity.hpp"

void Entity::onUpdate(sf::Time dt)
{
    this->_sprite.update(dt);
}
