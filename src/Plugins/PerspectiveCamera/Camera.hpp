/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera
*/

#pragma once

#include "ACam.hpp"

namespace Plugin {
    class Camera : public Raytracer::ACam {
    public:
        Camera(const Component::Vector3f &position, const Component::Vector3f &rotation, float field_of_view);

        ~Camera() override = default;
    };
}
