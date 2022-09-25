/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** constructor
*/

#include "core/App.hpp"
#include "utils/maths.hpp"

App::App(void) : _title("Game Engine"), _width(1080), _height(720) {
    // _init();
}

App::App(std::string const &title) : _title(title)
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    _width = desktop.width / 2;
    _height = desktop.height / 2;
    _init();
}

App::App(std::string const &title, unsigned int width, unsigned int height) :
_title(title), _width(width), _height(height)
{
    _init();
};