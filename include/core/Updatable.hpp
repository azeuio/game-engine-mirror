/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** Updatable
*/

#pragma once

#include <SFML/System/Clock.hpp>

/**
 * @brief Abstract base class for all updatable objects
 */
class Updatable {
private:
    sf::Clock _clock;
    sf::Time _dt;
    sf::Time _prevTime;
protected:
    /**
     * @brief Called before @ref onUpdate
     *
     * This is a pure virtual class that needs to be implemented by the
     * derived class.
     * This function should never be called directly
     *
     * @see onUpdate, update
     */
    virtual void _setup(void) {};
    /**
     * @brief Called after @ref onUpdate
     *
     * This is a pure virtual class that needs to be implemented by the
     * derived class.
     * This function should never be called directly
     *
     * @see onUpdate, update
     */
    virtual void _cleanup(void) {};
public:
    /**
     * @brief Calls _setup, onUpdate and _cleanup in this order
     * @see _setup, onUpdate, _cleanup
     */
    void update(void);
    /**
     * @brief Calls _setup, onUpdate and _cleanup in this order.
     * Does not calculate dt and use the given one
     * @param dt Time elapsed since last call to update
     * @see _setup, onUpdate, _cleanup
     */
    void update(sf::Time dt);

    /**
     * @brief Called on every update of the class
     *
     * This is a pure virtual function that needs to be implemented by the
     * derived class to define what happens on each update
     *
     * @param dt delta time in second elapsed since last call of update
     * @see update
     */
    virtual void onUpdate(float dt) = 0;
};
