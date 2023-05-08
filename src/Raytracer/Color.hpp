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
     * @brief Data structure representing a color with red, green, and blue components.
     * 
     * This data structure is used to define the color of a pixel.
     * 
     * @note The values of the components should be in the range [0.0, 1.0].
     */
    struct Color {
        double r;
        double g;
        double b;

        Color();

        /**
         * @brief Constructor for Color.
         * 
         * @param red The value for the red component of the color.
         * @param green The value for the green component of the color.
         * @param blue The value for the blue component of the color.
         */
        Color(double red, double green, double blue);

        /**
         * @brief Clamps the values of the color components to the range [0.0, 1.0].
         */
        void clamp();

        Component::Color operator*(double scalar) const;

        Component::Color operator*(const Component::Color &other) const;
    
        Component::Color operator+(const Component::Color &other) const;

        /**
         * @brief Converts the color components to integers in the range [0, 255].
         */
        [[nodiscard]] Component::Color toInteger() const;
    };
};
