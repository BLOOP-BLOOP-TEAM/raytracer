/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SimpleMaterialApi
*/

#pragma once

#include "IEntity.hpp"
#include <libconfig.h++>

#include "SimpleMaterial.hpp"

namespace Plugin {
    class SimpleMaterialApi {
    public:
        Raytracer::IMaterial *createMaterial(const libconfig::Setting &setting);
        const char *getName() const;
        Raytracer::CompType getType() const;
    };
}
