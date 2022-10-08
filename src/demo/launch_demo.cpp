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

static void moveBug(BugWalker &bug, const CustomEvent& event)
{
    if (event.key.code == sf::Keyboard::Space) {
        bug.setSpeed(-bug.getSpeed());
        bug.getAnimatedSprite().flipX();
    }
}

static void updateCamMovement(sf::Vector2f &camMovement,
const CustomEvent& event, float camSpeed, float dt)
{
    if (event.key.code == sf::Keyboard::Left) {
        camMovement.x = -dt * (camSpeed + (event.key.shift ? camSpeed : 0));
    }
    if (event.key.code == sf::Keyboard::Right) {
        camMovement.x = dt * (camSpeed + (event.key.shift ? camSpeed : 0));
    }
    if (event.key.code == sf::Keyboard::Up) {
        camMovement.y = -dt * (camSpeed + (event.key.shift ? camSpeed : 0));
    }
    if (event.key.code == sf::Keyboard::Down) {
        camMovement.y = dt * (camSpeed + (event.key.shift ? camSpeed : 0));
    }
}

static void resetCamMovement(sf::Vector2f &camMovement,
const CustomEvent& event)
{
    if ((event.key.code == sf::Keyboard::Left && camMovement.x < 0) ||
    (event.key.code == sf::Keyboard::Right && camMovement.x > 0)) {
        camMovement.x = 0;
    }
    if (
    (event.key.code == sf::Keyboard::Up && camMovement.y < 0) ||
    (event.key.code == sf::Keyboard::Down && camMovement.y > 0)) {
        camMovement.y = 0;
    }
}

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
    // bug.setSpeed(50);
    bug.setSpeed(0);
    app.getWindow().setFramerateLimit(0);
    sf::Vector2f camMovement;
    float camSpeed = 75;
    while (app.isRunning()) {
        if ((app.getCurrentFrame() % app.getFPS()) == 0) {
            app.setTitle(std::string(&"hello"[a++ % 5]));
        }
        while (app.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                moveBug(bug, event);
                updateCamMovement(camMovement, event, camSpeed,
                app.getDT().asSeconds());
            }
            if (event.type == sf::Event::KeyReleased) {
                resetCamMovement(camMovement, event);
            }
        }
        app.getCamera().move(camMovement);
        if (!app.isPaused()) {
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
