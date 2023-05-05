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
