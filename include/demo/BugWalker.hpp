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
    enum class Animation {
        IDLE,
        WALK,
        COUNT
    };

    BugWalker(void);

    using Entity::setAnimation;
    /**
     * @brief Sets current animation to one of the available one
     * @param animation Animation to switch to
    */
    void setAnimation(const Animation& animation)
    {
        this->getSprite().setAnimation((uint8_t)animation);
    }

    void onUpdate(sf::Time dt) override;
};
