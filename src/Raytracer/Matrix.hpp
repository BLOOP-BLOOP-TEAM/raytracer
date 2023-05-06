/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** MAtrix
*/

#pragma once

#include <cmath>
#include "Vector3f.hpp"

#pragma once

#include "Vector3f.hpp"

namespace Component {
    /**
     * @brief Data structure that defines a Matrix 3x3
     * 
     * This data structure defines a matrix 3x3 with all function that she needs
     */
    struct Matrix3x3 {
        double m[9]{};

        Matrix3x3();

        /**
         * @brief Constructor that creates a new 3x3 matrix and initializes its values using the provided arguments, in row-major order.
         * 
         * @param m0 The value in row 0, column 0.
         * @param m1 The value in row 0, column 1.
         * @param m2 The value in row 0, column 2.
         * @param m3 The value in row 1, column 0.
         * @param m4 The value in row 1, column 1.
         * @param m5 The value in row 1, column 2.
         * @param m6 The value in row 2, column 0.
         * @param m7 The value in row 2, column 1.
         * @param m8 The value in row 2, column 2.
         */
        Matrix3x3(double m0, double m1, double m2,
                  double m3, double m4, double m5,
                  double m6, double m7, double m8);

        /**
         * @brief Creates a 3x3 rotation matrix from Euler angles.
         * 
         * @param angles The Euler angles to use for creating the rotation matrix.
         */
        static Matrix3x3 fromEulerAngles(const Component::Vector3f &angles);

        Matrix3x3 operator*(const Matrix3x3 &other) const;

        Component::Vector3f operator*(const Component::Vector3f &vec) const;
    };

}
