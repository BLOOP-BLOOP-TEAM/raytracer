/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PerspectiveCameraApi
*/

#pragma once

#include <libconfig.h++>
#include "PerspectiveCamera.hpp"

namespace Plugin {
    class PerspectiveCameraApi {
    public:
        Raytracer::IEntity *createEntity(const libconfig::Setting &setting);

        const char *getName() const;

        Raytracer::CompType getType() const;
    };
}
