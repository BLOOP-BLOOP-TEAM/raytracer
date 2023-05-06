/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Vector3f
*/

#pragma once

#include <cmath>

namespace Component {
    /**
     * @brief The Vector3f data structure
     * 
     * This data structure is used to define positions of an object.
     * 
     * It contains the data to define the positions and override
     * operators that will make calculations on two positions.
     */
    struct Vector3f {
        float x;
        float y;
        float z;

        Vector3f();
        Vector3f(float x, float y, float z);

        Vector3f operator+(const Vector3f& v) const;

        Vector3f operator-(const Vector3f& v) const;

        Component::Vector3f operator*(float scalar) const;

        Vector3f operator*(const Vector3f& v) const;

        Vector3f operator/(float s) const;

        [[nodiscard]] float length() const;

        [[nodiscard]] Vector3f normalize() const;

        [[nodiscard]] float dot(const Vector3f& v) const;

        [[nodiscard]] Vector3f cross(const Vector3f& other) const;

        [[nodiscard]] Component::Vector3f rotate(const Vector3f& rotation) const;
    };
}
