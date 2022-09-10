/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** start_demo
*/

#include "demo/startDemo.hpp"
#include "demo/Demo.hpp"

int launchDemo(void)
{
    Demo app("SFML works!");
    CustomEvent event;
    sf::CircleShape circle(100.f);

    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setFillColor(sf::Color::Green);
    app.setClearColor(sf::Color::Red);
    while (app.isRunning()) {
        while (app.pollEvent(event)) {
            // Every event is handled by the app
        }
        app.update();
        app.draw();
        app.draw(circle);
        app.display();
    }
    return 0;
}
