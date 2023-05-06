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

    struct Matrix3x3 {
        double m[9]{};

        Matrix3x3();
        Matrix3x3(double m0, double m1, double m2,
                  double m3, double m4, double m5,
                  double m6, double m7, double m8);

        static Matrix3x3 fromEulerAngles(const Component::Vector3f &angles);
        Matrix3x3 operator*(const Matrix3x3 &other) const;
        Component::Vector3f operator*(const Component::Vector3f &vec) const;
    };

}
