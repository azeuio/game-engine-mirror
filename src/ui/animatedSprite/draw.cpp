/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** draw
*/

#include "ui/AnimatedSprite.hpp"

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states)
const
{
    states.transform *= getTransform();
    target.draw(_frame, states);
}
