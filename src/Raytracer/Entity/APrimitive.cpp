/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** APrimitive
*/

#include "APrimitive.hpp"

Raytracer::APrimitive::APrimitive(const std::string &type, const Component::Vector3f &position) : _typePrimitive(type),
                                                                                                  AEntity(Raytracer::CompType::PRIMITIVE,
                                                                                                          position)
{
}

bool Raytracer::APrimitive::intersect(Ray rayon)
{
    return (true);
}

void Raytracer::APrimitive::setMaterial(std::unique_ptr<IMaterial> material)
{

}
