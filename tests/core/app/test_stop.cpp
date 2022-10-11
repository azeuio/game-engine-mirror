/*
** EPITECH PROJECT, 2022
** game-engine
** File description:
** test_stop
*/

#include <criterion/criterion.h>

#include "tests/test_core/TestApp.hpp"

#ifdef DISPLAY
Test(App, stop)
{
    TestApp app;

    cr_assert_eq(app.isRunning(), true);
    app.stop();
    cr_assert_eq(app.isRunning(), false);
}
#endif
