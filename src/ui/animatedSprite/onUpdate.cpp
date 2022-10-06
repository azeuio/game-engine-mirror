/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** onUpdate
*/

#include "ui/AnimatedSprite.hpp"

void AnimatedSprite::onUpdate(sf::Time dt)
{
    sf::Vector2u framePos(0, 0);
    sf::Vector2u size = _spriteSheet.frameSize;
    auto [animStart, animLenght] = _spriteSheet.animations[_currAnimation];

    _frameIdx += dt.asSeconds() * _speed;
    if (_frameIdx >= animLenght) {
        _frameIdx -= (float)animLenght;
    }
    _frame.setTexture(_spriteSheet.texture);
    framePos.x = size.x * animStart +
    (size.x * (uint32_t)_frameIdx);
    _frame.setTextureRect(sf::IntRect(
        framePos.x,
        framePos.y,
        size.x,
        size.y));

}
