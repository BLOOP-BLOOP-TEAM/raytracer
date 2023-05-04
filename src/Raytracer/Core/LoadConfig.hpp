/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LoadConfig
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
    class LoadConfig {
        public:
            LoadConfig();
            ~LoadConfig() = default;

            std::vector<std::unique_ptr<Raytracer::Scene>> loadConfigFolder();
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
    };
}; // namespace Raytracer
