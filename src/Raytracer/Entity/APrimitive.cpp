/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** APrimitive
*/

#include "APrimitive.hpp"

#include <utility>

Raytracer::APrimitive::APrimitive(std::string type, const Component::Vector3f &position) : _typePrimitive(std::move(type)),
                                                                                                  AEntity(Raytracer::CompType::PRIMITIVE,
                                                                                                          position)
{
}

bool Raytracer::APrimitive::intersect(Ray rayon)
{
    return true;
}

void Raytracer::APrimitive::setMaterial(std::unique_ptr<IMaterial> material)
{
    _material = std::move(material);
}

Component::Vector3f Raytracer::APrimitive::getNormal(const Component::Vector3f &hit_point) const
{
    return {0, 0, 0};
}

Component::Color Raytracer::APrimitive::getColor(const Component::Vector3f &hit_point) const
{
    return {0, 0, 0};
}
