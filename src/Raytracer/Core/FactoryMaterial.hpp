/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FactoryMaterial
*/

#pragma once

#include <map>
#include <functional>
#include <string>
#include <libconfig.h++>
#include "AMaterial.hpp"

namespace Raytracer {
    /**
     * @brief The FactoryMaterial class provides a factory for creating materials.
     */
    class FactoryMaterial {
        public:
            FactoryMaterial() = default;

            ~FactoryMaterial() = default;

            /**
             * @brief Copy constructor for FactoryMaterial class (deleted).
             */
            FactoryMaterial(const FactoryMaterial&) = delete;

            /**
             * @brief Assignment operator for FactoryMaterial class (deleted).
             */
            FactoryMaterial& operator=(const FactoryMaterial&) = delete;

            /**
             * @brief Gets the singleton instance of FactoryMaterial class.
             */
            static FactoryMaterial& getInstance();

            /**
             * @brief Creates a material with the given name and configuration.
             * 
             * @param name The name of the material.
             * @param config The configuration of the material.
             */
            Raytracer::IMaterial *createMaterial(const std::string &name, const std::map<std::string, std::variant<double, int, std::string, bool>> &config);

            /**
             * @brief Destroys the given material.
             * 
             * @param material A pointer to the material to be destroyed.
             */
            void destroyMaterial(Raytracer::IMaterial *material);

            /**
             * @brief Adds a creator function for a material with the given name.
             * 
             * @param name The name of the material.
             * @param funcCreate The function that creates the material.
             * @param funcDestroy The function that destroys the material.
             */
            void addCreator(const std::string &name, std::function<Raytracer::IMaterial *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)> funcCreate, std::function<void(Raytracer::IMaterial *material)> funcDestroy);

            /**
             * @brief Gets a map of material creators.
             */
            [[nodiscard]] const std::map<std::string, std::pair<std::function<Raytracer::IMaterial *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>, std::function<void(Raytracer::IMaterial *material)>>>& getMaterials() const;

        private:
            std::map<std::string, std::pair<std::function<Raytracer::IMaterial *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>, std::function<void(Raytracer::IMaterial *material)>>> _materials;
    };
}
