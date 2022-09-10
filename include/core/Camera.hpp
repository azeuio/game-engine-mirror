/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** Camera
*/

#pragma once

#include <SFML/Graphics.hpp>

class Camera : public sf::View {
public:
    using sf::View::View;
    Camera(void)
    {
        setCenter(0, 0);
        setSize(0, 0);
    }
    Camera(sf::Vector2u const &size)
    {
        setCenter(0, 0);
        setSize(size.x, size.y);
    }
    Camera(sf::View const &view)
    {
        setCenter(view.getCenter());
        setSize(view.getSize());
        setViewport(view.getViewport());
        setRotation(view.getRotation());
    }
};
