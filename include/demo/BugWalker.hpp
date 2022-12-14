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
private:
    float _speed = 1.f;
public:
    enum class Animation {
        IDLE,
        WALK,
        COUNT
    };

    BugWalker(void);

    float getSpeed(void) const { return _speed; }

    using Entity::setAnimation;
    /**
     * @brief Sets current animation to one of the available one
     * @param animation Animation to switch to
    */
    void setAnimation(const Animation& animation)
    {
        this->getAnimatedSprite().setAnimation((uint8_t)animation);
    }
    /**
     * @brief Set the walk speed of the bug
     * @param s speed in pixel/second
     */
    void setSpeed(float s) { _speed = s; }

    void onUpdate(sf::Time dt) override;
};
