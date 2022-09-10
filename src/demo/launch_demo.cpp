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
    sf::CircleShape shape;
    sf::View &camera = app.getCamera();

    shape.setRadius(camera.getSize().x / 32.f);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setFillColor(sf::Color::Green);
    app.setClearColor(sf::Color::Red);
    camera.setCenter(0, 0);

    while (app.isRunning()) {
        while (app.pollEvent(event)) {
            // // Every event is handled by the app
        }
        app.update();
        app.draw();
        app.draw(shape);
        app.display();
    }
    printf("\n");
    return 0;
}
