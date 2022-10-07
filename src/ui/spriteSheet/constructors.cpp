/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** constructors
*/

#include "ui/SpriteSheet.hpp"

SpriteSheet::SpriteSheet(const std::string& texturePath,
const sf::Vector2u& dimensions,
const std::vector<std::pair<uint8_t, uint8_t>>& animations) :
_dimensions(dimensions), _animations(animations)
{
    _texture.loadFromFile(texturePath);
    _frameSize = _texture.getSize();
    _frameSize.x /= dimensions.x;
    _frameSize.y /= dimensions.y;
    if (animations.empty()) {
        _animations.push_back({0, (uint8_t)(_dimensions.x * _dimensions.y)});
    }
}

SpriteSheet::SpriteSheet(const sf::Texture& texture,
const sf::Vector2u& dimensions,
const std::vector<std::pair<uint8_t, uint8_t>>& animations) :
_texture(texture),
_dimensions(dimensions), _animations(animations)
{
    _frameSize = _texture.getSize();
    _frameSize.x /= dimensions.x;
    _frameSize.y /= dimensions.y;
    if (animations.empty()) {
        _animations.push_back({0, (uint8_t)(_dimensions.x * _dimensions.y)});
    }
}
