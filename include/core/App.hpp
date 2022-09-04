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
        int _width;
        int _height;
        sf::RenderWindow _window;
        sf::Color _clearColor = sf::Color::Black;
        struct keybindings keybindings = {
            .pause = sf::Keyboard::Key::Escape,
            .fullscreen = sf::Keyboard::Key::F11,
            .screenshot = sf::Keyboard::Key::F12
        };
    public:

        App(std::string const &title, int width, int height) :
        _title(title), _width(width), _height(height)
        {
            _window.create(sf::VideoMode(width, height), _title);
            _window.setFramerateLimit(60);
        };
        ~App() {
            _window.close();
        };

        bool isRunning(void) const { return _isRunning; }
        bool isPaused(void) const { return _isPaused; }
        sf::RenderWindow &getWindow(void) { return _window; }

        void setClearColor(sf::Color const &color) { _clearColor = color; }

        void stop(void);
        void toggleFullscreen(void);
        void takeScreenshot(void) const;
        virtual void update(void) = 0;
        /*
        \brief Polls for events and returns true if an event was polled

        Also handles the pause, fullscreen and screenshot keybindings
        */
        bool pollEvent(CustomEvent &event);
        /*
        \brief Draws the drawable on the window
        TODO: draw it on a display next
        */
        void draw(sf::Drawable const &drawable) { _window.draw(drawable); }
        /*
        \brief Clear the window with clear color, then draws all the drawable
        objects
        TODO: draw it on a display next
        TODO: add drawables to a list and draw them all at once
        */
        void draw(void);
        void display(void) { _window.display(); }
};
