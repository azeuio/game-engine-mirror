/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** test_constructor
*/

#include "criterion/criterion.h"

#include "ui/SpriteSheet.hpp"
#include "tests/prettyTests.hpp"

#ifdef DISPLAY

Test(constructor, empty)
{
    SpriteSheet sheet;

    cr_assert_eq(sheet.getAnimations().size(), 1);
    cr_assert_eq(sheet.getAnimations().at(0).first, 0);
    cr_assert_eq(sheet.getAnimations().at(0).second, 1);
    cr_assert_eq(sheet.getDimensions().x, 1);
    cr_assert_eq(sheet.getDimensions().y, 1);
    cr_assert_eq(sheet.getFrameSize().x, 0);
    cr_assert_eq(sheet.getFrameSize().y, 0);
}

Test(constructor, filepath)
{
    SpriteSheet sheet("assets/demo/bug_walker.png");

    cr_assert_eq(sheet.getAnimations().size(), 1);
    cr_assert_eq(sheet.getAnimations().at(0).first, 0);
    cr_assert_eq(sheet.getAnimations().at(0).second, 1);
    cr_assert_eq(sheet.getDimensions().x, 1);
    cr_assert_eq(sheet.getDimensions().y, 1);
    cr_assert_eq(sheet.getFrameSize().x, 64);
    cr_assert_eq(sheet.getFrameSize().y, 16);
}

Test(constructor, filepath_dimensions)
{
    SpriteSheet sheet("assets/demo/bug_walker.png", {4, 1});

    cr_assert_eq(sheet.getAnimations().size(), 1);
    cr_assert_eq(sheet.getAnimations().at(0).first, 0);
    cr_assert_eq(sheet.getAnimations().at(0).second, 4);
    cr_assert_eq(sheet.getDimensions().x, 4);
    cr_assert_eq(sheet.getDimensions().y, 1);
    cr_assert_eq(sheet.getFrameSize().x, 16);
    cr_assert_eq(sheet.getFrameSize().y, 16);
}

Test(constructor, texture)
{
    sf::Texture t;
    t.loadFromFile("assets/demo/bug_walker.png");
    SpriteSheet sheet(t);

    cr_assert_eq(sheet.getAnimations().size(), 1);
    cr_assert_eq(sheet.getAnimations().at(0).first, 0);
    cr_assert_eq(sheet.getAnimations().at(0).second, 1);
    cr_assert_eq(sheet.getDimensions().x, 1);
    cr_assert_eq(sheet.getDimensions().y, 1);
    cr_assert_eq(sheet.getFrameSize().x, 64);
    cr_assert_eq(sheet.getFrameSize().y, 16);
}

Test(constructor, texture_dimensions)
{
    sf::Texture t;
    t.loadFromFile("assets/demo/bug_walker.png");
    SpriteSheet sheet(t, {4, 1});
    bool tmp;

    cr_assert_eq(sheet.getAnimations().size(), 1);
    cr_assert_eq(sheet.getAnimations().at(0).first, 0);
    tmp = prettyEq<uint8_t>(sheet.getAnimations().at(0).second, 4);
    cr_assert(tmp);
    cr_assert_eq(sheet.getDimensions().x, 4);
    cr_assert_eq(sheet.getDimensions().y, 1);
    cr_assert_eq(sheet.getFrameSize().x, 16);
    cr_assert_eq(sheet.getFrameSize().y, 16);
}

#endif
