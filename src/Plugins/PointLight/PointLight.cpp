/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight
*/

#include "PointLight.hpp"

Plugin::PointLight::PointLight(const Component::Vector3f &position, const Component::Color &color, float intensity)
        : Raytracer::ALight("PointLight", position, color, intensity)
{
}
