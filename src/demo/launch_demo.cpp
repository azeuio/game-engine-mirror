/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** start_demo
*/

#include <functional>

#include "demo/startDemo.hpp"
#include "demo/Demo.hpp"
#include "core/EventManager.hpp"

int launchDemo(void)
{
    Demo app;
    CustomEvent event;
    sf::CircleShape circle(100.f);
    EventManager &manager = app.getEventManager();

    manager.subscribe(CustomEvent::EventType::Resized,
    [&](const CustomEvent &) { printf("resized\n"); });
    manager.subscribe(CustomEvent::Type::Pause,
    [](const CustomEvent &){
        static int a;
        printf("paused a %d\n", a++); });

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