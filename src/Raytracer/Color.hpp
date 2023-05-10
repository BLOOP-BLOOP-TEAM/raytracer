/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Color
*/

#pragma once

#include <algorithm>
#include <string>
#include <variant>

namespace Component {
    struct Color {
        double r;
        double g;
        double b;

        Color();
        Color(double red, double green, double blue);

        void clamp();

        Component::Color operator*(double scalar) const;
        Component::Color operator*(const Component::Color &other) const;
        Component::Color operator+(const Component::Color &other) const;
        [[nodiscard]] Component::Color toInteger() const;
    };
};
