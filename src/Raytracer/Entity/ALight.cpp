/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ALight
*/

#include "ALight.hpp"

#include <utility>

namespace Raytracer {
    ALight::ALight(std::string type, const Component::Vector3f &position, const Component::Vector3f &rotation, const Component::Color &color, double intensity)
            : AEntity(Raytracer::CompType::LIGHT, position, rotation), _typeLight(std::move(type)), _color(color), _intensity(intensity) {}

    const Component::Color& ALight::getColor() const
    {
        return _color;
    }

    double ALight::getIntensity() const
    {
        return _intensity;
    }

    const std::string &ALight::getTypeLight() const
    {
        return _typeLight;
    }
}
