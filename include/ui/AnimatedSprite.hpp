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
#include <bits/unique_ptr.h>
#include <SFML/Graphics.hpp>

#include "core/Updatable.hpp"
#include "ui/SpriteSheet.hpp"

/**
 * @brief Sprite that can be animated using a sprite sheet.
 */
class AnimatedSprite : public sf::Drawable, public sf::Transformable,
public Updatable {
private:
    /// @brief Index of the active frame of the current animation
    float _frameIdx = 0.F;
    /// @brief Index of the current animation
    uint8_t _currAnimation = 0.F;
    /// @brief Sprite representing the current frame of the animation
    sf::Sprite _frame;
    SpriteSheet _spriteSheet;
    /// @brief frame per seconds of each animation
    float _speed = 24.F;
protected:
    void _setup(void) final {
        // Virtual function is not needed
    };
    void _cleanup(void) final {
        // Virtual function is not needed
    };
public:
    AnimatedSprite(void) = default;
    explicit AnimatedSprite(std::string const& filepath)
    {
        setSpriteSheet(filepath);
    }

    /**
     * @brief Get the texture used as sprite sheet
     *
     * @return Texture used by this sprite
     */
    struct SpriteSheet &getSpriteSheet(void) { return _spriteSheet; }
    /**
     * @brief Get the Current rendered frame of the selected animation
     *
     * @return Current frame of the selected animation
     */
    sf::Sprite &getRenderedFrame(void) { return _frame; }
    /// @brief Get the current frame index
    float getCurrentFrame(void) const { return _frameIdx; }
    /// @brief Get the current animation index
    uint8_t getCurrentAnimation(void) const { return _currAnimation; }
    /// @brief Get the list of animations
    std::vector<std::pair<uint8_t, uint8_t>> &getAnimations(void)
    {
        return _spriteSheet.getAnimations();
    }
    /// @brief Get the size of one frame
    sf::Vector2u getFrameSize(void) const
    {
        return _spriteSheet.getFrameSize();
    }
    /// @brief Get the size of the sprite sheet
    sf::Vector2u getDimensions(void) const
    {
        return _spriteSheet.getDimensions();
    }
    float getSpeed(void) const { return _speed; }

    /**
     * @brief Set the texture to use as sprite sheet
     *
     * @param texture Texture to use
     */
    void setSpriteSheet(std::string const& filepath)
    {
        _spriteSheet.getTexture().loadFromFile(filepath);
        _spriteSheet.getTexture().loadFromFile(filepath);
        _spriteSheet.setFrameSize(_spriteSheet.getTexture().getSize());
        _spriteSheet.setDimensions({1, 1});
        _spriteSheet.setAnimations({{0, 1}});
    }
    /**
     * @brief Set the texture to use as sprite sheet
     *
     * @param texture Texture to use
     */
    void setSpriteSheet(const sf::Texture& texture)
    {
        _spriteSheet.setTexture(texture);
        _spriteSheet.setFrameSize(_spriteSheet.getTexture().getSize());
        _spriteSheet.setDimensions({1, 1});
        _spriteSheet.setAnimations({{0, 1}});
    }
    /**
     * @brief Set the texture to use as sprite sheet
     *
     * @param texture Texture to use
     */
    void setSpriteSheet(const SpriteSheet& spritesheet)
    {
        _spriteSheet = spritesheet;
    }
    /**
     * @brief Set the size of one frame of the sprite sheet
     *
     * @param frameSize size of one frame
     */
    void setFrameSize(sf::Vector2u frameSize)
    {
        _spriteSheet.setFrameSize(frameSize);
    }
    /**
     * @brief Set the size of the sprite sheet
     *
     */
    void setDimensions(sf::Vector2u dimensions)
    {
        _spriteSheet.setDimensions(dimensions);
    }
    /**
     * @brief Set the current animation
     */
    void setAnimation(uint8_t animation) { _currAnimation = animation; }
    /**
     * @brief Sets the speed in frame per second of each animation
     * @param fps speed in frame per second
     */
    void setSpeed(float fps) { _speed = fps; }

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
    override;

    /**
     * @brief Update the sprite
     *
     * @param dt Time since last update
     */
    void onUpdate(sf::Time dt) override;

};
