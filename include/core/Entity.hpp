/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** Entity
*/

#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable {
protected:
    sf::Sprite _sprite;
public:
    sf::Sprite &getSprite(void);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
};
