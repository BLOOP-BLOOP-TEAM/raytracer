/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereApi
*/

#pragma once


#include "IEntity.hpp"
#include "IMaterial.hpp"
#include <libconfig.h++>

namespace Plugin {
    class SphereApi {
    public:

        Raytracer::IEntity *createEntity(const libconfig::Setting &setting);
        const char *getName() const;
        Raytracer::CompType getType() const;
    };
}
