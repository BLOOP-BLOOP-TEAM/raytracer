/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PerspectiveCamera
*/

// PerspectiveCamera.cpp
#include "PerspectiveCamera.hpp"

Plugin::PerspectiveCamera::PerspectiveCamera(const Component::Vector3f &position, const Component::Vector3f &rotation, float field_of_view, float aspect_ratio)
        : Raytracer::ACam("PerspectiveCamera", position, rotation, field_of_view, aspect_ratio)
{
}
