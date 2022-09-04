/*
** EPITECH PROJECT, 2022
** game-engine
** File description:
** test_toggleFullscreen
*/

#include <criterion/criterion.h>

#include "tests/test_core/TestApp.hpp"

Test(App, toggleFullscreen)
{
    TestApp app("test", 1920, 1080);

    cr_assert_eq(app.isFullscreen(), false);
    app.toggleFullscreen();
    cr_assert_eq(app.isFullscreen(), true);
    app.toggleFullscreen();
    cr_assert_eq(app.isFullscreen(), false);
    app.stop();
}


Test(App, screen_size)
{
    TestApp app("test", 1920, 1080);
    uint width = app.getWidth();
    uint height = app.getHeight();

    cr_assert_eq(width, 1920);
    cr_assert_eq(height, 1080);
    app.toggleFullscreen();
    cr_assert_eq(width, 1920);
    cr_assert_eq(height, 1080);
    app.toggleFullscreen();
    cr_assert_eq(width, 1920);
    cr_assert_eq(height, 1080);
    app.stop();
}

Test(App, window_size)
{
    TestApp app("test", 1920, 1080);

    cr_assert_eq(app.getWindow().getSize().x, 1920);
    cr_assert_eq(app.getWindow().getSize().y, 1080);
    app.toggleFullscreen();
    cr_assert_neq(app.getWindow().getSize().x, 1920);
    cr_assert_neq(app.getWindow().getSize().y, 1080);
    app.toggleFullscreen();
    cr_assert_eq(app.getWindow().getSize().x, 1920);
    cr_assert_eq(app.getWindow().getSize().y, 1080);
    app.stop();
}
