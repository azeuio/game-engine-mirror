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

    _currentFrame++;
    _display.display();
    texture = _display.getTexture();
    sprite.setTexture(texture);
    _window.draw(sf::Sprite(sprite));
    _window.display();
}
