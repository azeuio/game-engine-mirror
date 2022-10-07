/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** SpriteSheet
*/

#pragma once

#include <SFML/Graphics.hpp>

class SpriteSheet {
private:
    /// @brief Texture that has every animations on it
    sf::Texture _texture = sf::Texture();
    /// @brief Size of one frame. Used as units for the sprite sheet
    sf::Vector2u _frameSize = {0u, 0u};
    /// @brief Size of the sprite sheet in frameSize units
    sf::Vector2u _dimensions = {1u, 1u};
    /// @brief Vector of pair of start idx, lenght of animation
    std::vector<std::pair<uint8_t, uint8_t>> _animations = {{0, 1}};
public:
        /// @brief Creates an empty SpriteSheet
        SpriteSheet(void) = default;
        /**
         * @brief Creates a new Spritesheet from a texture path
         * @param texturePath Path to the texture used by this sprite sheet
         * @param dimensions how many frame in width x height does the sheet
         * contains
         * @param anims Vector of pair of (start index, lenght of animation)
         * that represents every possible animation on the sprite sheet
        */
        explicit SpriteSheet(const std::string& texturePath,
        const sf::Vector2u& dimensions = {1u, 1u},
        const std::vector<std::pair<uint8_t, uint8_t>>& animations = {});
        /**
         * @brief Creates a new Spritesheet from a texture path
         * @param texturePath Path to the texture used by this sprite sheet
         * @param frameSize Dimensions of one frame on the texture
         * @param dimensions how many frame in width x height does the sheet
         * contains
         * @param anims Vector of pair of (start index, lenght of animation)
         * that represents every possible animation on the sprite sheet
        */
        explicit SpriteSheet(const sf::Texture& texture,
        const sf::Vector2u& dimensions = {1u, 1u},
        const std::vector<std::pair<uint8_t, uint8_t>>& animations = {});

        sf::Texture &getTexture(void) { return _texture; }
        sf::Vector2u getFrameSize(void) const { return _frameSize; }
        sf::Vector2u getDimensions(void) const { return _dimensions; }
        std::vector<std::pair<uint8_t, uint8_t>> getAnimations(void) const
        {
            return _animations;
        }

        void setTexture(const sf::Texture& texture) { _texture = texture; }
        void setFrameSize(const sf::Vector2u& size) { _frameSize = size; }
        void setDimensions(const sf::Vector2u& dimensions)
        {
            _dimensions = dimensions;
        }
        void setAnimations(
            const std::vector<std::pair<uint8_t, uint8_t>>& animations)
        {
            _animations = animations;
        }

        /**
         * @brief Adds an animation to the list of possible animations
         * @param animation pair of start index and lenght of animation
        */
        void addAnimation(const std::pair<uint8_t, uint8_t>& animation)
        {
            _animations.push_back(animation);
        }
        /// @brief Returns a rect that covers the nth frame of the sprite sheet
        sf::IntRect get(unsigned int n) const;
        /**
         * @brief Returns a rect that covers the nth frame of the given
         * animation
         * @param frameNb Frame number
         * @param animationId Id of the animation to search
         * @return Rectangle that covers the frame
         */
        sf::IntRect get(unsigned int n, unsigned int animationId) const;
};
