/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** takeScreenshot
*/

#include "core/App.hpp"

void App::takeScreenshot(void) const
{
    sf::Texture texture;
    sf::Image image;
    sf::Vector2u size = _window.getSize();
    texture.create(size.x, size.y);
    texture.update(_window);
    image = texture.copyToImage();
    // TODO: Add a screenshot counter
    image.saveToFile("screenshot.png");
}
