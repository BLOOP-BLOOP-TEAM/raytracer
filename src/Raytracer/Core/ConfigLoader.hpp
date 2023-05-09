/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConfigLoader
*/

#pragma once

#include <string>
#include <memory>
#include <map>
#include <cstdbool>
#include <functional>
#include <sstream>
#include <libconfig.h++>
#include "Scene.hpp"
#include "FactoryEntity.hpp"
#include "FactoryMaterial.hpp"

namespace Raytracer {
    /**
     * @brief The ConfigLoader class provides a method for loading scene configurations from files and folders.
     */
    class ConfigLoader {
        public:
            ConfigLoader() = default;
            ~ConfigLoader() = default;

            /**
             * @brief Loads all configuration files in a folder.
             */
            static std::unique_ptr<std::vector<std::unique_ptr<Raytracer::Scene>>> loadConfigFolder();

            /**
             * @brief Loads a configuration file at the given path.
             * 
             * @param path The path of the configuration file.
             */
            static std::unique_ptr<Raytracer::Scene> loadConfigFile(const std::string &path);

        protected:
        private:
            /**
             * @brief Loads a plugin type from a configuration file.
             * 
             * @param type The type of the plugin.
             * @param root The root setting of the configuration file.
             * @param scene The scene to add the plugin to.
             * @param materialsToApply A map of materials to apply to primitives.
             */
            static void loadPluginType(const std::string &type, const libconfig::Setting &root, Raytracer::Scene &scene, std::map<std::string, std::string> &materialsToApply);

            /**
             * @brief Loads all primitives from a configuration file.
             * 
             * @param root The root setting of the configuration file.
             * @param scene The scene to add the primitives to.
             * @param materialsToApply A map of materials to apply to primitives.
             */
            static void loadPrimitives(const libconfig::Setting &root, Raytracer::Scene &scene, std::map<std::string, std::string> &materialsToApply);

            /**
             * @brief Loads all lights from a configuration file.
             * 
             * @param root The root setting of the configuration file.
             * @param scene The scene to add the lights to.
             */
            static void loadLights(const libconfig::Setting &root, Raytracer::Scene &scene);

            /**
             * @brief Loads all materials from a configuration file.
             * 
             * @param root The root setting of the configuration file.
             * @param scene The scene to add the materials to.
             */
            static void loadMaterials(const libconfig::Setting &root, Raytracer::Scene &scene);

            /**
             * @brief Checks if a configuration file is valid.
             * 
             * @param cfg The configuration to check.
             * @param path The path of the configuration file.
             */
            static bool isAGoodConfigFile(libconfig::Config &cfg, const std::string &path);

            /**
             * @brief Applies materials to primitives in a scene.
             * 
             * @param scene The scene to apply the materials to.
             * @param materialsToApply A map of materials to apply to primitives.
             */
            static void applyMaterialsToPrimitives(Raytracer::Scene &scene, std::map<std::string, std::string> &materialsToApply);

            /**
             * @brief Gets a material from its name.
             * 
             * @param scene The scene containing the material.
             * @param name The name of the material.
             */
            static Raytracer::IMaterial *getMaterialFromName(const Raytracer::Scene &scene, const std::string &name);

            /**
             * @brief Extracts the file name from a file path.
             * 
             * @param path The file path.
             */
            static std::string extractFileName(const std::string &path);

            /**
             * @brief Transform the data parsed by libconfig into a map
             * 
             * @param setting The libonfig parsed data
             */
            static std::map<std::string, std::variant<double, int, std::string, bool>> transformSettingToDataMap(const libconfig::Setting &setting);
    };
};
