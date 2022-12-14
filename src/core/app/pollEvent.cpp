/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** pollEvent
*/

#include "core/App.hpp"
#include "core/keybindings.hpp"

static bool compareEqKeyEvent(sf::Event::KeyEvent eventA,
sf::Event::KeyEvent eventB)
{
    return (
        eventA.code == eventB.code &&
        eventA.control == eventB.control &&
        eventA.alt == eventB.alt &&
        eventA.shift == eventB.shift &&
        eventA.system == eventB.system
    );
}

bool App::pollEvent(CustomEvent &event)
{
    bool result = _window.pollEvent(event);

    if (!result)
        return false;
    if (event.type == sf::Event::Closed)
        stop();
    if (event.type == sf::Event::KeyPressed) {
        printf("press %d\n", (int)event.key.code);
        for (const KeyBinding kb : KEYBINDINGS) {
            if (!kb.activeOnKeyPress) continue;
            if (compareEqKeyEvent(event.key, kb.keyCombination)
            || compareEqKeyEvent(event.key, kb.altKeyCombination))
            {
                event.customType = kb.customType;
                event.type = sf::Event::Count;
                _eventManager.broadcast(event);
            }
        }
    } else if (event.type == sf::Event::KeyReleased) {
        printf("release %d\n", (int)event.key.code);
        for (const KeyBinding kb : KEYBINDINGS) {
            if (kb.activeOnKeyPress) continue;
            if (compareEqKeyEvent(event.key, kb.keyCombination)
            || compareEqKeyEvent(event.key, kb.altKeyCombination))
            {
                event.customType = kb.customType;
                event.type = sf::Event::Count;
                _eventManager.broadcast(event);
            }
        }
    } else {
        _eventManager.broadcast(event);
    }
    return true;
}
