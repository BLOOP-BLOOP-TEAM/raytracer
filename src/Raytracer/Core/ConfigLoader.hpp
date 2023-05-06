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
            /**
             * @brief Constructor for ConfigLoader class.
             */
            ConfigLoader();

            /**
             * @brief Default destructor for ConfigLoader class.
             */
            ~ConfigLoader() = default;

            /**
             * @brief Loads all configuration files in a folder.
             */
            std::unique_ptr<std::vector<std::unique_ptr<Raytracer::Scene>>> loadConfigFolder();

            /**
             * @brief Loads a configuration file at the given path.
             * 
             * @param path The path of the configuration file.
             */
            static std::unique_ptr<Raytracer::Scene> loadConfigFile(const std::string &path);

        protected:
        private:
            static void loadPluginType(const std::string &type, const libconfig::Setting &root, Raytracer::Scene &scene, std::map<std::string, std::string> &materialsToApply);
            static void loadPrimitives(const libconfig::Setting &root, Raytracer::Scene &scene, std::map<std::string, std::string> &materialsToApply);
            static void loadLights(const libconfig::Setting &root, Raytracer::Scene &scene);
            static void loadMaterials(const libconfig::Setting &root, Raytracer::Scene &scene);
            static bool isAGoodConfigFile(libconfig::Config &cfg, const std::string &path);
            static void applyMaterialsToPrimitives(Raytracer::Scene &scene, std::map<std::string, std::string> &materialsToApply);
            static Raytracer::IMaterial *getMaterialFromName(const Raytracer::Scene &scene, const std::string &name);

            static std::string extractFileName(const std::string &path);
    };
};
