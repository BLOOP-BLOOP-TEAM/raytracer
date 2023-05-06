/*
** EPITECH PROJECT, 2023
** raytracer [WSL: Ubuntu-20.04]
** File description:
** Vector3f
*/

#include "Vector3f.hpp"
#include "Vector3f.hpp"

Component::Vector3f::Vector3f() : x(0), y(0), z(0) {}
Component::Vector3f::Vector3f(double x, double y, double z) : x(x), y(y), z(z) {}

Component::Vector3f Component::Vector3f::operator+(const Vector3f& v) const
{
    return {x + v.x, y + v.y, z + v.z};
}

Component::Vector3f Component::Vector3f::operator-(const Vector3f& v) const
{
    return {x - v.x, y - v.y, z - v.z};
}

Component::Vector3f Component::Vector3f::operator*(double scalar) const
{
    return {x * scalar, y * scalar, z * scalar};
}

Component::Vector3f Component::Vector3f::operator*(const Vector3f& v) const
{
    return {x * v.x, y * v.y, z * v.z};
}

Component::Vector3f Component::Vector3f::operator/(double s) const
{
    return {x / s, y / s, z / s};
}

double Component::Vector3f::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

Component::Vector3f Component::Vector3f::rotate(const Vector3f& rotation) const
{
    double rx = rotation.x * M_PI / 180.0;
    double ry = rotation.y * M_PI / 180.0;
    double rz = rotation.z * M_PI / 180.0;

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

Component::Vector3f Component::Vector3f::cross(const Component::Vector3f &other) const
{
    return {y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x};
}

double Component::Vector3f::dot(const Component::Vector3f &v) const
{
    return x * v.x + y * v.y + z * v.z;
}

Component::Vector3f Component::Vector3f::normalize() const
{
    return *this / length();
}

