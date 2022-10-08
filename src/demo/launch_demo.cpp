/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** start_demo
*/

#include <functional>

#include "core/EventManager.hpp"
#include "demo/startDemo.hpp"
#include "demo/Demo.hpp"
#include "demo/BugWalker.hpp"

#include <string>
int launchDemo(void)
{
    Demo app("My game");
    CustomEvent event;
    sf::CircleShape circle(100.f);
    EventManager &manager = app.getEventManager();
    BugWalker bug;

    manager.subscribe(CustomEvent::EventType::Resized,
    [](const CustomEvent &) { printf("resized\n"); });
    manager.subscribe(CustomEvent::Type::Pause,
    [](const CustomEvent &){
        static int a;
        printf("paused a %d\n", a++);
    });
    bug.setAnimation(BugWalker::Animation::WALK);
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setFillColor(sf::Color::Green);
    app.setClearColor(sf::Color::Red);
    int a = 0;
    bug.setScale(5, 5);
    while (app.isRunning()) {
        if ((app.getCurrentFrame() % app.getFPS()) == 0) {
            app.setTitle(std::string(&"hello"[a++ % 5]));
        }
        while (app.pollEvent(event)) {
            // Every event is handled by the app
        }
        if (!app.isPaused()) {
            app.getCamera().move(0.1F, 0.F);
            app.update();
            bug.update();
        }
        app.draw();
        app.draw(circle);
        app.draw(bug);
        app.display();
    }
    return 0;
}
