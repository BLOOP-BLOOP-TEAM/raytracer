/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Rayon
*/

#pragma once

#include "Vector3f.hpp"

namespace Raytracer {
    struct Ray {

        Ray(Component::Vector3f origin, Component::Vector3f direction);

        Component::Vector3f origin;
        Component::Vector3f direction;

    };
};
