/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PointLightApi
*/

#pragma once

#include "IEntity.hpp"
#include "IMaterial.hpp"
#include <libconfig.h++>

namespace Plugin {
    class PointLightApi {
    public:
        Raytracer::IEntity *createEntity(const libconfig::Setting &setting);

        const char *getName() const;

        Raytracer::CompType getType() const;
    };
}