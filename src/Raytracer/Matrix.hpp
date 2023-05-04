/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Vector3f
*/

#pragma once

#include <cmath>
#include "Vector3f.hpp"

namespace Component {

    class Matrix3x3 {
    public:
        float m[9];

        Matrix3x3() {
            for (int i = 0; i < 9; ++i) {
                m[i] = 0;
            }
        }

        Matrix3x3(float m0, float m1, float m2,
                  float m3, float m4, float m5,
                  float m6, float m7, float m8) {
            m[0] = m0; m[1] = m1; m[2] = m2;
            m[3] = m3; m[4] = m4; m[5] = m5;
            m[6] = m6; m[7] = m7; m[8] = m8;
        }

        static Matrix3x3 fromEulerAngles(const Component::Vector3f &angles) {
            float sx = sinf(angles.x);
            float cx = cosf(angles.x);
            float sy = sinf(angles.y);
            float cy = cosf(angles.y);
            float sz = sinf(angles.z);
            float cz = cosf(angles.z);

            Matrix3x3 rx{
                    1, 0, 0,
                    0, cx, -sx,
                    0, sx, cx
            };

            Matrix3x3 ry{
                    cy, 0, sy,
                    0, 1, 0,
                    -sy, 0, cy
            };

            Matrix3x3 rz{
                    cz, -sz, 0,
                    sz, cz, 0,
                    0, 0, 1
            };

            return rz * ry * rx;
        }

        Matrix3x3 operator*(const Matrix3x3 &other) const {
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

        Component::Vector3f operator*(const Component::Vector3f &vec) const {
            return {
                    m[0] * vec.x + m[1] * vec.y + m[2] * vec.z,
                    m[3] * vec.x + m[4] * vec.y + m[5] * vec.z,
                    m[6] * vec.x + m[7] * vec.y + m[8] * vec.z
            };
        }
    };
}
