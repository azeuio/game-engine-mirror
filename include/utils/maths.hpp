/*
** EPITECH PROJECT, 2022
** game-engine-mirror
** File description:
** maths
*/

#pragma once

namespace utils {
namespace math {
template <typename T>
static inline T max(T a, T b) { return (a > b) ? a : b; }

template <typename T>
static T min(T a, T b) { return (a < b) ? a : b; }

template <typename T>
static inline T abs(T a) { return (a < 0) ? -a : a; }
} // namespace math
} // namespace utils