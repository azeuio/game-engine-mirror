/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** BugWalker
*/

#pragma once

#include "core/Entity.hpp"
#include "ui/AnimatedSprite.hpp"

/**
 * @brief Entity that walks
 * @see Entity
 */
class BugWalker : public Entity {
public:
    BugWalker(void);

    void onUpdate(sf::Time dt) override;
};
