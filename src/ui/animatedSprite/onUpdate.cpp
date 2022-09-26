/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** onUpdate
*/

#include "ui/AnimatedSprite.hpp"

void AnimatedSprite::onUpdate(float dt)
{
    _frameIdx += dt;
    if (_frameIdx < _animations[_currAnimation].second) return;
    _frameIdx -= _animations[_currAnimation].second;
}
