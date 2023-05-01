/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PlaneApi
*/

#pragma once

#include "IEntity.hpp"
#include "IMaterial.hpp"
#include <libconfig.h++>

namespace Plugin {
    class PlaneApi {
    public:
        Raytracer::IEntity *createEntity(const libconfig::Setting &setting);
        const char *getName() const;
        Raytracer::CompType getType() const;
    };
}

