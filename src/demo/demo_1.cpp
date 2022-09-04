/*
** EPITECH PROJECT, 2022
** game-engine
** File description:
** demo_1
*/

#include "demo/Demo.hpp"

void demo_1(void)
{
    Demo app("SFML works!", 1080, 720);
    CustomEvent event;
    sf::CircleShape shape(100.f);

    shape.setFillColor(sf::Color::Green);
    app.setClearColor(sf::Color::Red);
    while (app.isRunning()) {
        while (app.pollEvent(event)) {
            // Every event is handled by the app
        }
        app.update();
        app.draw();
        app.draw(shape);
        app.display();
    }
}
