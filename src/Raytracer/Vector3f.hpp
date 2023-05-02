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

        Vector3f operator/(float s) const
        {
            return {x / s, y / s, z / s};
        }

        [[nodiscard]] float length() const
        {
            return std::sqrt(x * x + y * y + z * z);
        }

        [[nodiscard]] Vector3f normalize() const {
            return *this / length();
        }

        [[nodiscard]] float dot(const Vector3f& v) const {
            return x * v.x + y * v.y + z * v.z;
        }

        [[nodiscard]] Vector3f rotate(const Vector3f& rotation) const
        {
            float rx = rotation.x * M_PI / 180.0f;
            float ry = rotation.y * M_PI / 180.0f;
            float rz = rotation.z * M_PI / 180.0f;

            Vector3f rotated;

            rotated.x = x * std::cos(ry) * std::cos(rz) - y * std::cos(ry) * std::sin(rz) + z * std::sin(ry);
            rotated.y = x * (std::sin(rx) * std::sin(ry) * std::cos(rz) + std::cos(rx) * std::sin(rz))
                        - y * (std::sin(rx) * std::sin(ry) * std::sin(rz) - std::cos(rx) * std::cos(rz))
                        - z * std::sin(rx) * std::cos(ry);
            rotated.z = x * (std::cos(rx) * std::sin(ry) * std::cos(rz) - std::sin(rx) * std::sin(rz))
                        - y * (std::cos(rx) * std::sin(ry) * std::sin(rz) + std::sin(rx) * std::cos(rz))
                        + z * std::cos(rx) * std::cos(ry);

            return rotated;
        }
    };
}
