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

namespace Raytracer {
    class LoadConfig {
        public:
            LoadConfig();
            ~LoadConfig() = default;

            void loadConfigFolder();
        protected:
        private:
            void loadConfigFile(const std::string &path);
            void loadPluginType(const std::string &type, const libconfig::Setting &root);
            void loadPrimitives(const libconfig::Setting &root);

            std::map<std::string, std::shared_ptr<Raytracer::FactoryEntity>> _factories;
    };
}; // namespace Raytracer
