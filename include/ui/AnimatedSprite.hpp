/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** AnimatedSprite
*/

#pragma once

#include <stdint.h>
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>

#include "core/Updatable.hpp"

/**
 * @brief Sprite that can be animated using a sprite sheet.
 */
class AnimatedSprite : public sf::Drawable, sf::Transformable,
public Updatable {
private:
    /// @brief Index of the active frame of the current animation
    float _frameIdx;
    /// @brief Index of the current animation
    uint8_t _currAnimation;
    /// @brief Vector of pair of start idx, lenght of animation
    std::vector<std::pair<uint8_t, uint8_t>> _animations;
    /// @brief Size of one frame. Used as units for the sprite sheet
    sf::Vector2u _frameSize;
    /// @brief Size of the sprite sheet in units
    sf::Vector2u _dimensions;
    /// @brief Sprite representing the current frame of the animation
    sf::Sprite _render;
    /// @brief Sprite sheet that has every animations on it
    sf::Texture _spriteSheet;
protected:
    virtual void _setup(void) final {};
    virtual void _cleanup(void) final {};
public:
    AnimatedSprite(void) = default;
    AnimatedSprite(std::string const& spriteSheetPath) {
        _spriteSheet.loadFromFile(spriteSheetPath);
        _render.setTexture(_spriteSheet);
    }

    /**
     * @brief Get the texture used as sprite sheet
     *
     * @return Texture used by this sprite
     */
    sf::Texture &getSpriteSheet(void) { return _spriteSheet; }
    /**
     * @brief Get the Current rendered frame of the selected animation
     *
     * @return Current frame of the selected animation
     */
    sf::Sprite &getRenderedFrame(void) { return _render; }
    /// @brief Get the current frame index
    float getCurrentFrame(void) { return _frameIdx; }
    /// @brief Get the current animation index
    uint8_t getCurrentAnimation(void) { return _currAnimation; }
    /// @brief Get the list of animations
    std::vector<std::pair<uint8_t, uint8_t>> &getAnimations(void)
    {
        return _animations;
    }
    /// @brief Get the size of one frame
    sf::Vector2u getFrameSize(void) { return _frameSize; }
    /// @brief Get the size of the sprite sheet
    sf::Vector2u getDimensions(void) { return _dimensions; }

    /**
     * @brief Set the texture to use as sprite sheet
     *
     * @param spriteSheet Texture to use
     */
    void setSpriteSheet(sf::Texture &spriteSheet)
    {
        _spriteSheet = spriteSheet;
        _render.setTexture(_spriteSheet);
    }
    /**
     * @brief Set the size of one frame of the sprite sheet
     *
     * @param frameSize size of one frame
     */
    void setFrameSize(sf::Vector2u frameSize) { _frameSize = frameSize; }
    /**
     * @brief Set the size of the sprite sheet
     *
     */
    void setDimensions(sf::Vector2u dimensions) { _dimensions = dimensions; }
    /**
     * @brief Set the current animation
     */
    void setAnimation(uint8_t animation) { _currAnimation = animation; }

    /**
     * @brief Go to the next frame of the current animation
     */
    void next(void);

    /**
     * @brief Draw the sprite to a render target
     *
     * @param target Render target to draw to
     * @param states Current render states
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(_render, states);
    }

    /**
     * @brief Update the sprite
     *
     * @param dt Time since last update
     */
    void onUpdate(float dt) override;

};
