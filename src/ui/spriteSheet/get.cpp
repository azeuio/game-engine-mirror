/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** get
*/

#include "ui/SpriteSheet.hpp"

sf::IntRect SpriteSheet::get(unsigned int n) const
{
    int width = _frameSize.x * _dimensions.x;
    int x = n * _frameSize.x;
    int y = (x / width) * _frameSize.y;

    x = x % width;
    return sf::IntRect(x, y, _frameSize.x, _frameSize.y);
}

sf::IntRect SpriteSheet::get(unsigned int n, unsigned int animationId) const
{
    int width = _frameSize.x * _dimensions.x;
    int x = 0;
    int y = 0;

    if (_animations.size() <= animationId ||
    n >= _animations.at(animationId).second) {
        return sf::IntRect(-1, -1, 0, 0);
    }
    x = (n + _animations.at(animationId).first) * _frameSize.x;
    y = (x / width) * _frameSize.y;
    x = x % width;
    return sf::IntRect(x, y, _frameSize.x, _frameSize.y);
}
