/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Matrix
*/

#include "Matrix.hpp"

Component::Matrix3x3::Matrix3x3()
{
    for (float & i : m) {
        i = 0;
    }
}

Component::Matrix3x3::Matrix3x3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7,
                                float m8)
                                {
    m[0] = m0; m[1] = m1; m[2] = m2;
    m[3] = m3; m[4] = m4; m[5] = m5;
    m[6] = m6; m[7] = m7; m[8] = m8;
}

Component::Matrix3x3 Component::Matrix3x3::fromEulerAngles(const Component::Vector3f &eulerAngles)
{
    float cos_x = cosf(eulerAngles.x);
    float sin_x = sinf(eulerAngles.x);
    float cos_y = cosf(eulerAngles.y);
    float sin_y = sinf(eulerAngles.y);
    float cos_z = cosf(eulerAngles.z);
    float sin_z = sinf(eulerAngles.z);

    Component::Matrix3x3 Rx = {
            1, 0, 0,
            0, cos_x, -sin_x,
            0, sin_x, cos_x,
    };

    Component::Matrix3x3 Ry = {
            cos_y, 0, sin_y,
            0, 1, 0,
            -sin_y, 0, cos_y,
    };

    Component::Matrix3x3 Rz = {
            cos_z, -sin_z, 0,
            sin_z, cos_z, 0,
            0, 0, 1,
    };

    // Modifiez l'ordre des multiplications de matrice ici, par exemple : Rz * Rx * Ry
    return Rz * Ry * Rx;
}
Component::Matrix3x3 Component::Matrix3x3::operator*(const Component::Matrix3x3 &other) const
{
    Matrix3x3 result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result.m[i * 3 + j] += m[i * 3 + k] * other.m[k * 3 + j];
            }
        }
    }
    return result;
}

Component::Vector3f Component::Matrix3x3::operator*(const Component::Vector3f &vec) const
{
    return {
            m[0] * vec.x + m[1] * vec.y + m[2] * vec.z,
            m[3] * vec.x + m[4] * vec.y + m[5] * vec.z,
            m[6] * vec.x + m[7] * vec.y + m[8] * vec.z
    };
}
