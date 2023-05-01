/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Color
*/

#pragma once

namespace Component {
    struct Color {
        int r = 0;
        int g = 0;
        int b = 0;
        Color() : r(0), g(0), b(0) {};
        Color(int red, int green, int blue) : r(red), g(green), b(blue) {};
    };
};
