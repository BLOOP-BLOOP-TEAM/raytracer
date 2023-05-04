/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Vector3f
*/

#pragma once

#include <cmath>

namespace Component {
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

        [[nodiscard]] Vector3f rotate(const Vector3f& rotation) const;
    };
}
