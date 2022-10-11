/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** App
*/

#pragma once

#include <stdint.h>
#include <string>
#include <SFML/Graphics.hpp>

#include "core/Updatable.hpp"
#include "core/CustomEvent.hpp"
#include "core/EventManager.hpp"

class App : public Updatable {
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
    unsigned int _width;
    unsigned int _height;
    sf::RenderWindow _window;
    sf::RenderTexture _display;
    sf::Color _clearColor = sf::Color::Black;
    struct keybindings keybindings = {
        .pause = sf::Keyboard::Key::Escape,
        .fullscreen = sf::Keyboard::Key::F11,
        .screenshot = sf::Keyboard::Key::F12
    };
    sf::View _camera;
    EventManager _eventManager;
    unsigned int _fps = 60u;
    unsigned long _currentFrame = 0UL;

    void _keepViewConsitant(void);
    /**
     * @brief Called by the constructor of the class.
     * should not be directly called
     */
    void _init(void);
    void _setupDefaultEventListeners(void);
    void _recreateWindow(unsigned int width, unsigned int height,
    sf::Uint32 style = 7U);
protected:
    /**
     * @brief Called when an instance is created.
     * This function is made to be overwritten
     */
    virtual void onInit(void) {
        // Made to be overridden
    };
    void _setup(void) override;
    void _cleanup(void) override
    {
        // Made to be overriden
    };
public:
    explicit App(std::string const &title);
    App(std::string const &title, unsigned int width, unsigned int height);
    ~App() override = default;

    bool isRunning(void) const { return _isRunning; }
    bool isPaused(void) const { return _isPaused; }
    bool isFullscreen(void) const { return _isFullscreen; }
    unsigned int getWidth(void) const { return _width; }
    unsigned int getHeight(void) const { return _height; }
    sf::RenderWindow &getWindow(void) { return _window; }
    sf::RenderTexture &getDisplay(void) { return _display; }
    sf::View &getCamera(void) { return _camera; }
    EventManager &getEventManager(void) { return _eventManager; }
    unsigned int getFPS(void) const { return _fps; }
    unsigned long getCurrentFrame(void) const { return _currentFrame; }

    void setTitle(std::string const &title) {
        _title = title;
        _window.setTitle(title);
    }
    void setClearColor(sf::Color const &color) { _clearColor = color; }
    void setFPS(uint32_t fps) { _fps = fps; _window.setFramerateLimit(fps); }

    void stop(void);
    void toggleFullscreen(void);
    /*
    \brief Takes a screenshot of the current window and saves it in the
    screenshots/ folder
    */
    void takeScreenshot(void) const;
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

    /** Centers the window on screen */
    void centerWindow(void);
};
