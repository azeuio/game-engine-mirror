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

#include <string>
int launchDemo(void)
{
    Demo app("My game");
    CustomEvent event;
    sf::CircleShape circle(100.f);
    EventManager &manager = app.getEventManager();

    while (app.getWindow().pollEvent(event));
    manager.subscribe(CustomEvent::EventType::Resized,
    [](const CustomEvent &) { printf("resized\n"); });
    manager.subscribe(CustomEvent::Type::Pause,
    [](const CustomEvent &){
        static int a;
        printf("paused a %d\n", a++);
    });
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setFillColor(sf::Color::Green);
    app.setClearColor(sf::Color::Red);
    int a = 0;
    while (app.isRunning()) {
        if ((app.getCurrentFrame() % app.getFPS()) == 0) {
            app.setTitle(std::string(&"hello"[a++ % 5]));
        }
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
