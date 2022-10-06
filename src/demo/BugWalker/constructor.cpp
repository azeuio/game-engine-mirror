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

    sprite.getSpriteSheet().frameSize = {16, 16};
    sprite.getSpriteSheet().animations = {{0, 4}};
    sprite.getSpriteSheet().dimensions = {1, 4};
    sprite.setSpeed(4);
    setSprite(sprite);
}
