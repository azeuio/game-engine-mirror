/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** test_get
*/

#include "criterion/criterion.h"
#include "criterion/logging.h"
#include "ui/SpriteSheet.hpp"

#ifdef DISPLAY

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
    SpriteSheet sheet("assets/tests/bug_walker.png", {4, 1});
    sf::IntRect rect = sheet.get(0);

    cr_assert(logRectEq(rect, 0, 0, 16, 16));
}

Test(get, first_anim_first)
{
    SpriteSheet sheet("assets/tests/bug_walker.png", {4, 1}, {{1, 3}});
    sf::IntRect rect = sheet.get(0, 0);

    cr_assert(logRectEq(rect, 16, 0, 16, 16));
}

Test(get, third)
{
    SpriteSheet sheet("assets/tests/bug_walker.png", {4, 1});
    sf::IntRect rect = sheet.get(3);

    cr_assert(logRectEq(rect, 48, 0, 16, 16));
}

Test(get, first_anim_second)
{
    SpriteSheet sheet("assets/tests/bug_walker.png", {4, 1}, {{1, 3}});
    sf::IntRect rect = sheet.get(1, 0);

    cr_assert(logRectEq(rect, 32, 0, 16, 16));
}

Test(get, second_anim_first)
{
    SpriteSheet sheet("assets/tests/bug_walker.png", {4, 1}, {{1, 3}, {0, 2}});
    sf::IntRect rect = sheet.get(0, 1);

    cr_assert(logRectEq(rect, 0, 0, 16, 16));
}

Test(get, invalid_animation)
{
    SpriteSheet sheet("assets/tests/bug_walker.png", {4, 1}, {{1, 3}, {0, 2}});
    sf::IntRect rect = sheet.get(0, -2);

    cr_assert(logRectEq(rect, -1, -1, 0, 0));
    sheet = SpriteSheet("assets/tests/bug_walker.png", {4, 1}, {{1, 3}, {0, 2}});
    rect = sheet.get(0, 4);
    cr_assert(logRectEq(rect, -1, -1, 0, 0));
}

Test(get, invalid_frame_index)
{
    SpriteSheet sheet("assets/tests/bug_walker.png", {4, 1}, {{1, 3}, {0, 2}});
    sf::IntRect rect = sheet.get(-2, 0);

    cr_assert(logRectEq(rect, -1, -1, 0, 0));
    sheet = SpriteSheet("assets/tests/bug_walker.png", {4, 1}, {{1, 3}, {0, 2}});
    rect = sheet.get(4, 0);
    cr_assert(logRectEq(rect, -1, -1, 0, 0));
}

Test(get, _2d_sheet)
{
    SpriteSheet sheet("assets/tests/bug_walker_square.png", {2, 2}, {{0, 4}, {2, 2}});
    sf::IntRect rect = sheet.get(0, 0);

    cr_assert(logRectEq(rect, 0, 0, 16, 16));
    sheet = SpriteSheet("assets/tests/bug_walker_square.png", {2, 2}, {{0, 4}, {2, 2}});
    rect = sheet.get(2, 0);
    cr_assert(logRectEq(rect, 0, 16, 16, 16));
    sheet = SpriteSheet("assets/tests/bug_walker_square.png", {2, 2}, {{0, 4}, {2, 2}});
    rect = sheet.get(3, 0);
    cr_assert(logRectEq(rect, 16, 16, 16, 16));
    sheet = SpriteSheet("assets/tests/bug_walker_square.png", {2, 2}, {{0, 4}, {2, 2}});
    rect = sheet.get(1, 1);
    cr_assert(logRectEq(rect, 16, 16, 16, 16));
}

#endif
