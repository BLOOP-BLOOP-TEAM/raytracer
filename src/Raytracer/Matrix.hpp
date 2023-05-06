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
        float m[9]{};

        Matrix3x3();
        Matrix3x3(float m0, float m1, float m2,
                  float m3, float m4, float m5,
                  float m6, float m7, float m8);

        static Matrix3x3 fromEulerAngles(const Component::Vector3f &angles);
        Matrix3x3 operator*(const Matrix3x3 &other) const;
        Component::Vector3f operator*(const Component::Vector3f &vec) const;
    };

}
