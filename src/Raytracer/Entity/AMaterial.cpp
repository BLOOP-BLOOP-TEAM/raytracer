/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AMaterial
*/

#include <utility>
#include "AMaterial.hpp"

Raytracer::AMaterial::AMaterial(std::string type) : _type(std::move(type))
{
}

const std::string &Raytracer::AMaterial::getType()
{
    return (_type);
}

Component::Color
Raytracer::AMaterial::computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                   const Component::Vector3f &lightDirection, float lightIntensity) const {
    return Component::Color();
}
