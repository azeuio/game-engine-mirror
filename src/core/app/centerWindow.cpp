/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** centerWindow
*/

#include "core/App.hpp"
#include "utils/maths.hpp"

using namespace utils::maths;

void App::centerWindow(void)
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::Vector2i winPos(
        (int)(desktop.width / 2.f - _width / 2.f),
        (int)(desktop.height / 2.f - _height / 2.f));

    _window.setPosition(sf::Vector2i(
        min<int>(desktop.width - _width, winPos.x),
        max<int>(desktop.height / 50, winPos.y)));
}