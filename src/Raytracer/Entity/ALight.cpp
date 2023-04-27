/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ALight
*/

#include "ALight.hpp"

Raytracer::ALight::ALight(const std::string &type, const Component::Vector3f &position)
        : AEntity("Light", position), _typeLight(type)
{
}
