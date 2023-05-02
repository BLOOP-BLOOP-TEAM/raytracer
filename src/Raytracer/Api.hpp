/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Api
*/

#pragma once

#include "IEntity.hpp"
#include <libconfig.h++>

#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT
#endif

extern "C"
{
    enum LibType { ENTITY, MATERIAL };

    EXPORT Raytracer::IEntity *CreateEntity(const libconfig::Setting &setting);

    EXPORT void destroyEntity(Raytracer::IEntity *entity);

    EXPORT Raytracer::IMaterial *CreateMaterial(const libconfig::Setting &setting);

    EXPORT void destroyMaterial(Raytracer::IMaterial *material);

    EXPORT const char *getName();

    EXPORT LibType getType();
}
