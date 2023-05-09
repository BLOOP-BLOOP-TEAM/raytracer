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

#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT
#endif

extern "C"
{
    enum LibType { ENTITY, MATERIAL };

    EXPORT Raytracer::IEntity *createEntity(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting);

    EXPORT void destroyEntity(Raytracer::IEntity *entity);

    EXPORT Raytracer::IMaterial *createMaterial(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting);

    EXPORT void destroyMaterial(Raytracer::IMaterial *material);

    EXPORT const char *getName();

    EXPORT LibType getType();
}
