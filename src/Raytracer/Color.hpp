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
        float r;
        float g;
        float b;

        Color();
        Color(float red, float green, float blue);

        void clamp();

        Component::Color operator*(float scalar) const;
        Component::Color operator*(const Component::Color &other) const;
        Component::Color operator+(const Component::Color &other) const;
        [[nodiscard]] Component::Color toInteger() const;
    };
};
