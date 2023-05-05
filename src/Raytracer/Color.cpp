/*
** EPITECH PROJECT, 2023
** raytracer [WSL: Ubuntu-20.04]
** File description:
** Color
*/

#include "Color.hpp"

Component::Color::Color() : r(0), g(0), b(0) {}

Component::Color::Color(int red, int green, int blue) : r(red), g(green), b(blue) {}

void Component::Color::clamp()
{
    r = std::clamp(r, 0, 255);
    g = std::clamp(g, 0, 255);
    b = std::clamp(b, 0, 255);
}

Component::Color Component::Color::operator*(float scalar) const
{
    return Component::Color(r * scalar, g * scalar, b * scalar);
}


Component::Color Component::Color::operator*(const Component::Color &other) const
{
    return Component::Color(r * other.r, g * other.g, b * other.b);
}

Component::Color Component::Color::operator+(const Component::Color &other) const
{
    return Component::Color(r + other.r, g + other.g, b + other.b);
}
