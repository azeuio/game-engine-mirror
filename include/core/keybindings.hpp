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
#include <SFML/Window/Event.hpp>

#include "core/CustomEvent.hpp"

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
    CONFIRM,
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
    sf::Event::KeyEvent keyCombination;
    sf::Event::KeyEvent altKeyCombination;
    int joystickButton;
    bool isCustomEvent;
    CustomEvent::Type customType = CustomEvent::Type::Count;
    sf::Event::EventType sfType = sf::Event::Count;
    bool activeOnKeyPress = true;
};

sf::Event::KeyEvent newKeyEvent(
    sf::Keyboard::Key keyCode,
    bool ctrlPressed = false,
    bool altPressed = false,
    bool shiftPressed = false,
    bool systemPressed = false
)
{
    return {
        .code = keyCode,
        .alt = altPressed,
        .control = ctrlPressed,
        .shift = shiftPressed,
        .system = systemPressed
    };
}

const std::array<const struct KeyBinding, (std::size_t)KeybindingsAction::COUNT>
KEYBINDINGS = {
    // SCREENSHOT
    (struct KeyBinding){
        newKeyEvent(sf::Keyboard::F2),
        newKeyEvent(sf::Keyboard::F2),
        -1,
        true,
        CustomEvent::Type::Screenshot
    },
    // FULLSCREEN
    (struct KeyBinding){
        newKeyEvent(sf::Keyboard::F11),
        newKeyEvent(sf::Keyboard::F2),
        -1,
        true,
        CustomEvent::Type::Fullscreen,
        sf::Event::Count,
        false
    },
    // PAUSE
    (struct KeyBinding){
        newKeyEvent(sf::Keyboard::Escape),
        newKeyEvent(sf::Keyboard::P),
        1,
        true,
        CustomEvent::Type::Pause
    }
};
