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

double Raytracer::AMaterial::getRefractivity() const {
    return _refractivity;
}

double Raytracer::AMaterial::getRefractiveIndex() const {
    return _refractiveIndex;
}
