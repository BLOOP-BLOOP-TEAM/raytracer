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

            void loadConfigFolder();
            static std::unique_ptr<Raytracer::Scene> loadConfigFile(const std::string &path);
        protected:
        private:
            static void loadPluginType(const std::string &type, const libconfig::Setting &root, Raytracer::Scene &scene);
            static std::vector<Raytracer::IEntity *> loadPrimitives(const libconfig::Setting &root);
            static void loadMaterials(const libconfig::Setting &root);
            static bool isAGoodConfigFile(libconfig::Config &cfg, const std::string &path);
            static Raytracer::FactoryEntity _factoryEntity;
            static Raytracer::FactoryMaterial _factoryMaterial;
    };
}; // namespace Raytracer
