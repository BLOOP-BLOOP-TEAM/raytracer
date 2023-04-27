/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ALight
*/

#include "ALight.hpp"

namespace Raytracer {
    ALight::ALight(const std::string &type, const Component::Vector3f &position, const Component::Color &color, float intensity)
            : AEntity(Raytracer::CompType::LIGHT, position), _typeLight(type), _color(color), _intensity(intensity) {}

    const Component::Color& ALight::getColor() const {
        return _color;
    }

    float ALight::getIntensity() const {
        return _intensity;
    }
}
