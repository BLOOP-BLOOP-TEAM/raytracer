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
        int r;
        int g;
        int b;

        Color();
        Color(int red, int green, int blue);

        void clamp();

        Component::Color operator*(float scalar) const;
        Component::Color operator*(const Component::Color &other) const;
        Component::Color operator+(const Component::Color &other) const;
    };
};
