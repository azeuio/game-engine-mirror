/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** flip
*/

#include "ui/AnimatedSprite.hpp"

void AnimatedSprite::flip(void)
{
    flipX();
}

void AnimatedSprite::flipX(void)
{
    float halfFrame = ((float)getFrameSize().x / 2.f);

    _isFlippedX = !_isFlippedX;
    setScale(-getScale().x, getScale().y);
    setOrigin(
    halfFrame - (getOrigin().x - halfFrame),
    getOrigin().y);
}

void AnimatedSprite::flipY(void)
{
    float halfFrame = ((float)getFrameSize().y / 2.f);

    _isFlippedY = !_isFlippedY;
    setOrigin(
    getOrigin().x,
    halfFrame - (getOrigin().y - halfFrame));
    setScale(getScale().x, -getScale().y);
}
