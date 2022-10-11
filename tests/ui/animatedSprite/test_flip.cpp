/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** test_flip
*/

#include "criterion/criterion.h"

#include "ui/AnimatedSprite.hpp"
#include "tests/prettyTests.hpp"

#ifdef DISPLAY

Test(flip, x_origin_0_percent)
{
    AnimatedSprite sprite("assets/demo/bug_walker.png", {4, 1});

    sprite.setOrigin(0, 0);
    sprite.flip();
    cr_assert(prettyEq<float>(sprite.getOrigin().x, 16));
    sprite.flip();
    cr_assert(prettyEq<float>(sprite.getOrigin().x, 0));
}

Test(flip, x_origin_50_percent)
{
    AnimatedSprite sprite("assets/demo/bug_walker.png", {4, 1});

    sprite.setOrigin(8, 0);
    sprite.flip();
    cr_assert(prettyEq<float>(sprite.getOrigin().x, 8));
    sprite.flip();
    cr_assert(prettyEq<float>(sprite.getOrigin().x, 8));
}

Test(flip, x_origin_25_percent)
{
    AnimatedSprite sprite("assets/demo/bug_walker.png", {4, 1});

    sprite.setOrigin(12, 0);
    sprite.flip();
    cr_assert(prettyEq<float>(sprite.getOrigin().x, 4));
    sprite.flip();
    cr_assert(prettyEq<float>(sprite.getOrigin().x, 12));
}

Test(flip, y_origin_0_percent)
{
    AnimatedSprite sprite("assets/demo/bug_walker.png", {4, 1});

    sprite.setOrigin(0, 0);
    sprite.flipY();
    cr_assert(prettyEq<float>(sprite.getOrigin().y, 16));
    sprite.flipY();
    cr_assert(prettyEq<float>(sprite.getOrigin().y, 0));
}

Test(flip, y_origin_50_percent)
{
    AnimatedSprite sprite("assets/demo/bug_walker.png", {4, 1});

    sprite.setOrigin(0, 8);
    sprite.flipY();
    cr_assert(prettyEq<float>(sprite.getOrigin().y, 8));
    sprite.flipY();
    cr_assert(prettyEq<float>(sprite.getOrigin().y, 8));
}

Test(flip, y_origin_25_percent)
{
    AnimatedSprite sprite("assets/demo/bug_walker.png", {4, 1});

    sprite.setOrigin(0, 12);
    sprite.flipY();
    cr_assert(prettyEq<float>(sprite.getOrigin().y, 4));
    sprite.flipY();
    cr_assert(prettyEq<float>(sprite.getOrigin().y, 12));
}

#endif
