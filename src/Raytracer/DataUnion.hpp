/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** DataUnion
*/

#pragma once

#include <string>

namespace Raytracer {
    union DataUnion {
        double d;
        int i;
        std::string *s;
        bool b;
    };
}
