/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** BugWalker
*/

#pragma once

#include "core/Entity.hpp"

class BugWalker : public Entity {
public:
    BugWalker() {
        sf::Texture *texture = new sf::Texture;

        texture->loadFromFile("assets/demo/bug_walker.png");
        _sprite.setTexture(*texture, true);
    }
};
