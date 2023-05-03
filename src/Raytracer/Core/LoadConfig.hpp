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
#include <libconfig.h++>
#include "FactoryEntity.hpp"

static const std::string FOLDER_NAME = "Scenes";

static const std::string PRIMITIVES = "primitives";
static const std::string CAMERA = "camera";
static const std::string LIGHTS = "lights";

namespace Raytracer {
    class LoadConfig {
        public:
            LoadConfig();
            ~LoadConfig() = default;

            void loadConfigFolder();
        protected:
        private:
            static void loadConfigFile(const std::string &path);
            static void loadPluginType(const std::string &type, const libconfig::Setting &root);
            static void loadPrimitives(const libconfig::Setting &root);

    };
}; // namespace Raytracer
