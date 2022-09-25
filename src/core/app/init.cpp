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

    _recreateWindow(_width, _height);
    centerWindow();
    _display.create(
        max(desktop.width, _width),
        max(desktop.height, _height));
    _camera = sf::View(_display.getView());;
    _camera.setCenter(0, 0);
    _display.setView(_camera);
    _keepViewConsitant();
    _setupDefaultEventListeners();
    onInit();
    sf::Keyboard::setVirtualKeyboardVisible(true);
}