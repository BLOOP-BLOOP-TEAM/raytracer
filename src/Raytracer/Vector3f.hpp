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
        double x;
        double y;
        double z;

        Vector3f();
        Vector3f(double x, double y, double z);

        Vector3f operator+(const Vector3f& v) const;

        Vector3f operator-(const Vector3f& v) const;

        Component::Vector3f operator*(double scalar) const;

        Vector3f operator*(const Vector3f& v) const;

        Vector3f operator/(double s) const;

        [[nodiscard]] double length() const;

        [[nodiscard]] Vector3f normalize() const;

        [[nodiscard]] double dot(const Vector3f& v) const;

        [[nodiscard]] Vector3f cross(const Vector3f& other) const;

        [[nodiscard]] Component::Vector3f rotate(const Vector3f& rotation) const;
    };
}
