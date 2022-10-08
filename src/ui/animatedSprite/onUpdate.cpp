/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** onUpdate
*/

#include "ui/AnimatedSprite.hpp"

void AnimatedSprite::onUpdate(sf::Time dt)
{
    auto animLenght = _spriteSheet.getAnimations().at(_currAnimation).second;

    _frameIdx += dt.asSeconds() * _speed;
    if (_frameIdx >= animLenght) {
        _frameIdx -= (float)animLenght;
    }
    _frame.setTexture(_spriteSheet.getTexture());
    sf::IntRect r = _spriteSheet.get((uint32_t)_frameIdx);
    _frame.setTextureRect(r);
}
