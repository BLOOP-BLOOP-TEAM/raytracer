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
