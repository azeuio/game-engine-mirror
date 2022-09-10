/*
** EPITECH PROJECT, 2022
** game-engine
** File description:
** display
*/

#include "core/App.hpp"

void App::display(void)
{
    sf::Texture texture;
    sf::Sprite sprite;

    _display.display();
    texture = _display.getTexture();
    sprite.setTexture(texture);
    // sprite.setScale(0.5, 0.5);
    _window.draw(sf::Sprite(sprite));
    _window.display();
}
