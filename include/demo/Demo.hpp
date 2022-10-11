/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** Demo
*/

#pragma once

#include "core/App.hpp"

class Demo : public App {
    public:
        using App::App;
        void onUpdate(sf::Time dt) final;
};

void demo_1(void);
