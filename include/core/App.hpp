/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** App
*/

#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "core/CustomEvent.hpp"
#include "core/Camera.hpp"

class App {
public:
    struct keybindings {
        sf::Keyboard::Key pause;
        sf::Keyboard::Key fullscreen;
        sf::Keyboard::Key screenshot;
    };
private:
    bool _isFullscreen = false;
    bool _isRunning = true;
    bool _isPaused = false;
    std::string _title;
    uint _width;
    uint _height;
    sf::RenderWindow _window;
    sf::RenderTexture _display;
    sf::Color _clearColor = sf::Color::Black;
    struct keybindings keybindings = {
        .pause = sf::Keyboard::Key::Escape,
        .fullscreen = sf::Keyboard::Key::F11,
        .screenshot = sf::Keyboard::Key::F12
    };
    Camera _camera;
    void _keepViewConsitant(void);
public:
    App(void) : _title("Game Engine"), _width(1080), _height(720) {}
    explicit App(std::string const &title) : _title(title)
    {
        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
        sf::View view;

        _width = desktop.width / 2;
        _height = desktop.height / 2;
        // makes sure the display is at the same resolution as the screen
        _display.create(desktop.width, desktop.height);
        _camera = Camera(_display.getView());
        // makes sure the display is centered on the window
        _camera.setViewport(sf::FloatRect(0, 0, 1 / 2.f, 1 / 2.f));
        _camera.setSize((float)_width, (float)_height);
        _camera.setCenter(0, 0);
        _display.setView(_camera);
        _window.create(sf::VideoMode(_width, _height), _title);
        _window.setPosition(
            sf::Vector2i(desktop.width / 4, desktop.height / 4));
        _window.setFramerateLimit(60);
    }
    App(std::string const &title, uint width, uint height) :
    _title(title), _width(width), _height(height)
    {
        _window.create(sf::VideoMode(width, height), _title);
        _window.setFramerateLimit(60);
        _display.create(width, height);
    };
    virtual ~App() = default;

    bool isRunning(void) const { return _isRunning; }
    bool isPaused(void) const { return _isPaused; }
    bool isFullscreen(void) const { return _isFullscreen; }
    uint getWidth(void) const { return _width; }
    uint getHeight(void) const { return _height; }
    sf::RenderWindow &getWindow(void) { return _window; }
    sf::RenderTexture &getDisplay(void) { return _display; }
    sf::View &getCamera(void) { return _camera; }

    void setClearColor(sf::Color const &color) { _clearColor = color; }

    void stop(void);
    void toggleFullscreen(void);
    /*
    \brief Takes a screenshot of the current window and saves it in the
    screenshots/ folder
    */
    void takeScreenshot(void) const;
    /** @brief Updates the window and calls onUpdate()
     */
    void update(void) {
        _display.setView(_camera);
        onUpdate();
    };
    virtual void onUpdate(void) = 0;
    /*
    \brief Polls for events and returns true if an event was polled

    Also handles the pause, fullscreen and screenshot keybindings
    */
    bool pollEvent(CustomEvent &event);
    /*
    \brief Draws the drawable on the window
    */
    void draw(sf::Drawable const &drawable);
    /*
    \brief Clear the window with clear color, then draws all the drawable
    objects
    */
    void draw(void);
    void display(void);
};
