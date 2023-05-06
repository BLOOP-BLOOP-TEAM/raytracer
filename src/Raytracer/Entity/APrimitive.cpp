/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** APrimitive
*/

#include <utility>
#include <iostream>
#include "APrimitive.hpp"

Raytracer::APrimitive::APrimitive(std::string type, const Component::Vector3f &position) : _typePrimitive(std::move(type)),
                                                                                                  AEntity(Raytracer::CompType::PRIMITIVE,
                                                                                                          position), _material(nullptr)
{
}

float Raytracer::APrimitive::intersect(const Ray &ray) const
{
    std::cout << "APrimitive::intersect" << std::endl;
    return 0;
}

void Raytracer::APrimitive::setMaterial(IMaterial *material)
{
    if (material == nullptr)
        return;
    std::cout << "APrimitive::setMaterial real" << std::endl;
    _material = material;
}

Component::Vector3f Raytracer::APrimitive::getNormal(const Component::Vector3f &hit_point) const
{
    return {0, 0, 0};
}

Component::Color Raytracer::APrimitive::getColor(const Component::Vector3f &hit_point) const
{
    return {0, 0, 0};

}

Raytracer::IMaterial& Raytracer::APrimitive::getMaterial() const
{
    return *_material;
}

const std::string &Raytracer::APrimitive::getTypePrimitive() const
{
    return _typePrimitive;
}
