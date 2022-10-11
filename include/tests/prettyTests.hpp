/*
** EPITECH PROJECT, 2022
** game-engine-mirror [WSL : Ubuntu]
** File description:
** prettyTests
*/

#pragma once

#include "criterion/criterion.h"
#include "criterion/logging.h"

template <typename T>
bool prettyEq(const T& a, const T& b)
{
    bool res = a == b;
    std::string err;

    if (!res) {
        cr_log_error("a (%ld %luu) != b (%ld %luu)", (int64_t)a, (uint64_t)a,
        (int64_t)b, (uint64_t)b);
    }
    return res;
}

template <typename T>
bool prettyNeq(const T& a, const T& b)
{
    bool res = a != b;
    std::string err;

    if (!res) {
        cr_log_error("a (%ld %luu) == b (%ld %luu)", (int64_t)a, (uint64_t)a,
        (int64_t)b, (uint64_t)b);
    }
    return res;
}

template bool prettyEq(const char&, const char&);
template bool prettyEq(const int&, const int&);
template bool prettyEq(const long&, const long&);
template bool prettyEq(const long long&, const long long&);
template bool prettyEq(const unsigned char&, const unsigned char&);
template bool prettyEq(const unsigned int&, const unsigned int&);
template bool prettyEq(const unsigned long&, const unsigned long&);
template bool prettyEq(const unsigned long long&,
const unsigned long long&);
template bool prettyEq(const double&, const double&);
template bool prettyNeq(const char&, const char&);
template bool prettyNeq(const int&, const int&);
template bool prettyNeq(const long&, const long&);
template bool prettyNeq(const long long&, const long long&);
template bool prettyNeq(const unsigned char&, const unsigned char&);
template bool prettyNeq(const unsigned int&, const unsigned int&);
template bool prettyNeq(const unsigned long&, const unsigned long&);
template bool prettyNeq(const unsigned long long&,
const unsigned long long&);
template bool prettyNeq(const double&, const double&);
