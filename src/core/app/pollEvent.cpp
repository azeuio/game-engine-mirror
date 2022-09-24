/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** pollEvent
*/

#include "core/App.hpp"
#include "core/keybindings.hpp"

void App::_keepViewConsitant(void)
{
    auto windowSize = sf::Vector2f(_window.getSize());

    _camera.setSize(windowSize);
    _display.setView(_camera);
}

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

    if (result == false)
        return false;
    if (event.type == sf::Event::Closed)
        stop();
    if (event.type == sf::Event::KeyPressed) {
        // if (compareEqKeyEvent(event.key, KEYBINDINGS[0].keyCombination)) {
        //     printf("pa\n");
        // }
        for (std::size_t i = 0; i < (std::size_t)KeybindingsAction::COUNT; i++)
        {
            if (compareEqKeyEvent(event.key, KEYBINDINGS[i].keyCombination)) {
                printf("broadcasting %d\n", i);
                event.customType = KEYBINDINGS[i].customType;
                event.type = sf::Event::Count;
                _eventManager.broadcast(event);
            }
        }
        
        // if (event.key.code == keybindings.pause) {
        //     _isPaused = !_isPaused;
        //     event.customType = CustomEvent::Type::Pause;
        //     event.pauseToggle.isPaused = _isPaused;
        // }
        // if (event.key.code == keybindings.fullscreen)
        //     toggleFullscreen();
        // if (event.key.code == keybindings.screenshot)
        //     takeScreenshot();
    } else {
        _eventManager.broadcast(event);
    }
    if (event.type == sf::Event::Resized) {
        _keepViewConsitant();
    }
    return true;
}
