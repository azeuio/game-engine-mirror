/*
** EPITECH PROJECT, 2022
** game-engine
** File description:
** test_toggleFullscreen
*/

#include <criterion/criterion.h>

#include "tests/set_env_display.hpp"
#include "tests/test_core/TestApp.hpp"

#if (DISPLAY == 1)
Test(App, toggleFullscreen)
{
    TestApp app;

    cr_assert_eq(app.isFullscreen(), false);
    app.toggleFullscreen();
    cr_assert_eq(app.isFullscreen(), true);
    app.toggleFullscreen();
    cr_assert_eq(app.isFullscreen(), false);
    app.stop();
}

Test(App, screen_size)
{
    TestApp app;
    uint width = app.getWidth();
    uint height = app.getHeight();

    cr_assert_eq(width, 1080);
    cr_assert_eq(height, 720);
    app.toggleFullscreen();
    cr_assert_eq(width, 1080);
    cr_assert_eq(height, 720);
    app.toggleFullscreen();
    cr_assert_eq(width, 1080);
    cr_assert_eq(height, 720);
    app.stop();
}

Test(App, window_size)
{
    TestApp app("Game Engine", 1080, 720);

    cr_assert_eq(app.getWindow().getSize().x, 1080);
    cr_assert_eq(app.getWindow().getSize().y, 720);
    app.toggleFullscreen();
    cr_assert_neq(app.getWindow().getSize().x, 1080);
    cr_assert_neq(app.getWindow().getSize().y, 720);
    app.toggleFullscreen();
    cr_assert_eq(app.getWindow().getSize().x, 1080);
    cr_assert_eq(app.getWindow().getSize().y, 720);
    app.stop();
}
#endif
