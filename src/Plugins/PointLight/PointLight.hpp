/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight
*/

#pragma once

#include "ALight.hpp"

namespace Plugin {
    class PointLight : public Raytracer::ALight {
    public:
        PointLight(const Component::Vector3f &position, const Component::Color &color, float intensity);

        ~PointLight() override = default;
    };
}

