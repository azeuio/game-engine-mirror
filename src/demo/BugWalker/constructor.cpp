/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** constructor
*/

#include "demo/BugWalker.hpp"

BugWalker::BugWalker(void)
{
    AnimatedSprite sprite("assets/demo/bug_walker.png");

    sprite.getSpriteSheet().setFrameSize({16, 16});
    sprite.getSpriteSheet().setAnimations({{0, 1}, {0, 4}});
    sprite.getSpriteSheet().setDimensions({4, 1});
    sprite.setSpeed(4);
    setSprite(sprite);
}
