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

        Vector3f() : x(0), y(0), z(0) {}
        Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}

        Vector3f operator+(const Vector3f& v) const
        {
            return {x + v.x, y + v.y, z + v.z};
        }

        Vector3f operator-(const Vector3f& v) const
        {
            return {x - v.x, y - v.y, z - v.z};
        }

        Component::Vector3f operator*(float scalar) const {
            return {x * scalar, y * scalar, z * scalar};
        }

        Vector3f operator*(const Vector3f& v) const
        {
            return {x * v.x, y * v.y, z * v.z};
        }


        Vector3f operator/(float s) const
        {
            return {x / s, y / s, z / s};
        }

        [[nodiscard]] float length() const
        {
            return std::sqrt(x * x + y * y + z * z);
        }

        Vector3f normalize() const {
            return *this / length();
        }

        [[nodiscard]] float dot(const Vector3f& v) const {
            return x * v.x + y * v.y + z * v.z;
        }

        Vector3f cross(const Vector3f& other) const {
            return Vector3f(y * other.z - z * other.y,
                            z * other.x - x * other.z,
                            x * other.y - y * other.x);
        }
    };
}
