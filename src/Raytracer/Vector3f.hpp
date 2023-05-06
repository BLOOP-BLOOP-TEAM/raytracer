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
     * 
     * It contains some functions too that will make calculations.
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

        /**
         * @brief Computes the length of the vector
         */
        [[nodiscard]] float length() const;

        /**
         * @brief Normalizes the vector
         */
        [[nodiscard]] Vector3f normalize() const;

        /**
         * @brief Computes the dot product between two vectors
         * 
         * @param v The vector to compute the dot product with
         */
        [[nodiscard]] float dot(const Vector3f& v) const;

        /**
         * @brief Computes the cross product between two vectors
         * 
         * @param other The vector to compute the cross product with
         */
        [[nodiscard]] Vector3f cross(const Vector3f& other) const;

        /**
         * @brief Rotates the vector according to the given rotation angles.
         *
         * This function rotates the vector according to the given rotation angles.
         * The rotation angles are expressed in degrees and correspond to rotations
         * around the X, Y, and Z axis respectively.
         *
         * @param rotation The rotation angles around the X, Y, and Z axis respectively.
         */
        [[nodiscard]] Component::Vector3f rotate(const Vector3f& rotation) const;
    };
}
