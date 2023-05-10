/*
** EPITECH PROJECT, 2023
** raytracer [WSL: Ubuntu-20.04]
** File description:
** Color
*/

#include "Color.hpp"

Component::Color::Color() : r(0.0), g(0.0), b(0.0) {}

Component::Color::Color(double red, double green, double blue) : r(red), g(green), b(blue) {}

void Component::Color::clamp()
{
    r = std::clamp(r, 0.0, 1.0);
    g = std::clamp(g, 0.0, 1.0);
    b = std::clamp(b, 0.0, 1.0);
}

Component::Color Component::Color::operator*(double scalar) const
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

Component::Color Component::Color::toInteger() const
{
    int red = static_cast<int>(r * 255);
    int green = static_cast<int>(g * 255);
    int blue = static_cast<int>(b * 255);
    return Component::Color(red, green, blue);
}
