/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** APrimitive
*/

#include <utility>
#include <iostream>
#include "APrimitive.hpp"

Raytracer::APrimitive::APrimitive(std::string type, const Component::Vector3f &position, const Component::Vector3f &rotation) : _typePrimitive(std::move(type)),
                                                                                                  AEntity(Raytracer::CompType::PRIMITIVE,
                                                                                                          position, rotation), _material(nullptr)
{
}

void Raytracer::APrimitive::setMaterial(IMaterial *material)
{
    if (material == nullptr)
        return;
    _material = material;
}

Raytracer::IMaterial& Raytracer::APrimitive::getMaterial() const
{
    return *_material;
}

const std::string &Raytracer::APrimitive::getTypePrimitive() const
{
    return _typePrimitive;
}
