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

    /**
     * @brief Creates an entity object.
     * 
     * @param setting Map of data for the entity.
     */
    EXPORT Raytracer::IEntity *createEntity(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting);

    /**
     * @brief Destroys an entity object.
     * 
     * @param entity A pointer to the IEntity object to be destroyed.
     */
    EXPORT void destroyEntity(Raytracer::IEntity *entity);

    /**
     * @brief Creates a material object.
     * 
     * @param setting Map of data for the material.
     */
    EXPORT Raytracer::IMaterial *createMaterial(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting);

    /**
     * @brief Destroys a material object.
     */
    EXPORT void destroyMaterial(Raytracer::IMaterial *material);

    /**
     * @brief Create a skybox object
     * 
     * @param setting Map of data for the skybox.
     */
    EXPORT Raytracer::ISkybox *createSkybox(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting);

    EXPORT void destroySkybox(Raytracer::ISkybox *skybox);

    /**
     * @brief Retrieves the name of the library.
     */
    EXPORT const char *getName();

    /**
     * @brief Retrieves the type of the library (entity or material).
     */
    EXPORT LibType getType();
}
