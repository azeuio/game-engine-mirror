/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** init
*/

#include "core/App.hpp"
#include "utils/maths.hpp"

using namespace utils::math;

void App::_init()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::View view;
    sf::Vector2f halfSize(_width / 2.f, _height / 2.f);
    sf::Vector2i winPos(
        desktop.width / 2.f - halfSize.x,
        desktop.height / 2.f - halfSize.y);

    _window.create(sf::VideoMode(desktop.width, desktop.height), _title);
    _window.setSize({_width, _height});
    _window.setFramerateLimit(60);
    _window.setPosition(sf::Vector2i(
        min<int>(desktop.width - _width, winPos.x),
        max<int>(desktop.height / 50, winPos.y)));
    _display.create(
        max(desktop.width, _width),
        max(desktop.height, _height));
    _camera = sf::View(_display.getView());;
    _camera.setCenter(0, 0);
    _display.setView(_camera);
    _keepViewConsitant();
    onInit();
}