/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Api
*/

#pragma once

#include <variant>
#include "IEntity.hpp"
#include "IMaterial.hpp"
#include "ISkybox.hpp"

#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT
#endif

extern "C"
{
    enum LibType { ENTITY, MATERIAL, SKYBOX };

    EXPORT Raytracer::IEntity *createEntity(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting);

    EXPORT void destroyEntity(Raytracer::IEntity *entity);

    EXPORT Raytracer::IMaterial *createMaterial(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting);

    EXPORT void destroyMaterial(Raytracer::IMaterial *material);

    EXPORT Raytracer::ISkybox *createSkybox(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting);

    EXPORT void destroySkybox(Raytracer::ISkybox *skybox);

    EXPORT const char *getName();

    EXPORT LibType getType();
}
