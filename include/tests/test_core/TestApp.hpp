/*
** EPITECH PROJECT, 2022
** game-engine
** File description:
** TestApp
*/

#pragma once

#include "core/App.hpp"

class TestApp : public App {
    public:
        TestApp(void) : App("TestApp", 1080, 720) {};
        using App::App;

        void onUpdate(sf::Time dt) final {
            // Doesn't need to be implemented
        };

};
