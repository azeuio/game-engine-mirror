/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** keybindings
*/

#pragma once

#include <array>
#include <vector>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>

enum class KeybindingsAction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    JUMP,
    RUN,
    CROUCH,
    TOGGLE_INVENTORY,
    INTERACT,
    CONFIRM = INTERACT, /// Alias for INTERACT
    RETURN,
    NEXT_ELEMENT,
    SKIP,
    SAVE,
    HOME,
    SCREENSHOT,
    FULLSCREEN,
    PAUSE,
    COUNT
};

struct KeyCombination {
    sf::Keyboard::Key key;
    bool ctrl;
    bool alt;
    bool shift;
};

struct KeyBinding {
    KeyCombination keyCombination;
    KeyCombination altKeyCombination;
    unsigned int joystickButton;
};

std::array<struct KeyBinding, (int)KeybindingsAction::COUNT>
const KEYBINDINGS = {
    // UP
    {
        {sf::Keyboard::W, false, false, false},
        {sf::Keyboard::Up, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // DOWN
    {
        {sf::Keyboard::S, false, false, false},
        {sf::Keyboard::Down, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // LEFT
    {
        {sf::Keyboard::A, false, false, false},
        {sf::Keyboard::Left, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // RIGHT
    {
        {sf::Keyboard::D, false, false, false},
        {sf::Keyboard::Right, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // JUMP
    {
        {sf::Keyboard::Space, false, false, false},
        {sf::Keyboard::KeyCount, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // RUN
    {
        {sf::Keyboard::LShift, false, false, false},
        {sf::Keyboard::RShift, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // CROUCH
    {
        {sf::Keyboard::LControl, false, false, false},
        {sf::Keyboard::RControl, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // TOGGLE_INVENTORY
    {
        {sf::Keyboard::I, false, false, false},
        {sf::Keyboard::I, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // INTERACT
    {
        {sf::Keyboard::E, false, false, false},
        {sf::Keyboard::Enter, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // RETURN
    {
        {sf::Keyboard::Escape, false, false, false},
        {sf::Keyboard::BackSpace, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // NEXT_ELEMENT
    {
        {sf::Keyboard::Tab, false, false, false},
        {sf::Keyboard::Tab, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // SKIP
    {
        {sf::Keyboard::Enter, false, false, false},
        {sf::Keyboard::KeyCount, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // SAVE
    {
        {sf::Keyboard::S, true, false, false},
        {sf::Keyboard::KeyCount, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // HOME
    {
        {sf::Keyboard::KeyCount, false, false, false},
        {sf::Keyboard::KeyCount, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // SCREENSHOT
    {
        {sf::Keyboard::F2, false, false, false},
        {sf::Keyboard::KeyCount, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // FULLSCREEN
    {
        {sf::Keyboard::F11, false, false, false},
        {sf::Keyboard::KeyCount, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    },
    // PAUSE
    {
        {sf::Keyboard::Escape, false, false, false},
        {sf::Keyboard::P, false, false, false},
        (unsigned int)sf::Joystick::ButtonCount
    }
};
