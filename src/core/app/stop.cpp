/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** stop
*/

#include "core/App.hpp"

void App::stop(void)
{
    _isRunning = false;
    _window.close();
}
