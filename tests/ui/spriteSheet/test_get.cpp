/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** test_get
*/

#include "criterion/criterion.h"
#include "criterion/logging.h"
#include "ui/SpriteSheet.hpp"

static bool rectEq(const sf::IntRect &rect, int x, int y, int w, int h)
{
    return (
        rect.left == x &&
        rect.top == y &&
        rect.width == w &&
        rect.height == h
    );
}

static bool logRectEq(const sf::IntRect &rect, int x, int y, int w, int h)
{
    bool res = rectEq(rect, x, y, w, h);

    if (!res) {
        cr_log_error("got rect(%d, %d, %d, %d), expected rect(%d, %d, %d, %d)",
        rect.left, rect.top, rect.width, rect.height,
        x, y, w, h);
    }
    return res;
}

Test(get, first)
{
    SpriteSheet sheet("assets/demo/bug_walker.png", {4, 1});
    sf::IntRect rect = sheet.get(0);

    cr_assert(logRectEq(rect, 0, 0, 16, 16));
}

Test(get, first_anim_first)
{
    SpriteSheet sheet("assets/demo/bug_walker.png", {4, 1});
    sf::IntRect rect = sheet.get(0, 0);

    cr_assert(logRectEq(rect, 0, 0, 16, 16));
}


// TODO: make more tests
