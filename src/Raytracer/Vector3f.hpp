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
            return Vector3f (x + v.x, y + v.y, z + v.z);
        }

        Vector3f operator-(const Vector3f& v) const
        {
            return Vector3f(x - v.x, y - v.y, z - v.z);
        }

        Vector3f operator*(float s) const
        {
            return Vector3f(x * s, y * s, z * s);
        }

        Vector3f operator/(float s) const
        {
            return Vector3f(x / s, y / s, z / s);
        }

        float length() const
        {
            return std::sqrt(x * x + y * y + z * z);
        }

        Vector3f normalize() const {
            return *this / length();
        }

        float dot(const Vector3f& v) const {
            return x * v.x + y * v.y + z * v.z;
        }
    };
}
