/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Color
*/

#pragma once

#include <algorithm>

namespace Component {
    struct Color {
        int r = 0;
        int g = 0;
        int b = 0;
        Color() : r(0), g(0), b(0) {};
        Color(int red, int green, int blue) : r(red), g(green), b(blue) {};

        void clamp()
        {
            r = std::clamp(r, 0, 255);
            g = std::clamp(g, 0, 255);
            b = std::clamp(b, 0, 255);
        }

        Component::Color operator*(float scalar) const {
            return Component::Color(r * scalar, g * scalar, b * scalar);
        }

        Component::Color& operator+(const Component::Color &other) {
            r += other.r;
            g += other.g;
            b += other.b;
            return *this;
        }
    };
};
