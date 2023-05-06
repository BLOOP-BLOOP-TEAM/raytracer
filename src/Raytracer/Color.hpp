/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Color
*/

#pragma once

#include <algorithm>

namespace Component {
    /**
     * @brief data structure of Color
     * 
     * This data structure is used to define the color of a pixel
     * 
     * It contains all the data needed by a pixel and overriding operators
     * to make calculations between two pixels.
     */
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
