/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PerspectiveCamera
*/

#pragma once

#include "ACam.hpp"

namespace Plugin {
    class PerspectiveCamera : public Raytracer::ACam {
    public:
        PerspectiveCamera(const Component::Vector3f &position, const Component::Vector3f &rotation, float field_of_view, float aspect_ratio);

        ~PerspectiveCamera() override = default;
    };
}
