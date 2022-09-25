/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** Entity
*/

#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, sf::Transformable {
protected:
    sf::Sprite _sprite;
public:
    sf::Sprite &getSprite(void);
};
