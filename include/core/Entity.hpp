/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** Entity
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "ui/AnimatedSprite.hpp"

/**
 * @brief Basic Entity class, the building block of everything in this engine
 * Needs to be derived to be useful
 */
class Entity : public sf::Drawable, public sf::Transformable {
protected:
    /// @brief Sprite of the entity
    AnimatedSprite _sprite;
public:
    Entity(void) = default;
    /**
     * @brief Get the AnimatedSprite
     *
     * @return The animated sprite of this entity
     * @see AnimatedSprite
     */
    AnimatedSprite &getSprite(void);

    /**
     * @brief Draw the sprite to a render target
     *
     * @param target Render target to draw to
     * @param states Current render states
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    final;
};
