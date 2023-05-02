/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AMaterial
*/

#include "CompType.hpp"
#include "AMaterial.hpp"

Raytracer::AMaterial::AMaterial(const std::string &type) : _type(type)
{
}

const std::string &Raytracer::AMaterial::getType(void)
{
    return (_type);
}
