/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** draw
*/

#include "core/Entity.hpp"

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(_sprite, states);
}