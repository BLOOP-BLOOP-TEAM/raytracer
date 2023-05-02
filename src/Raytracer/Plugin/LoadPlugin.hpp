/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LoadPlugin
*/

#pragma once

#include <string>
#include <map>
#include <functional>
#include <vector>
#include "IEntity.hpp"
#include "FactoryEntity.hpp"
#include "FactoryMaterial.hpp"

namespace Raytracer {
    class LoadPlugin {
    public:
        LoadPlugin();
        ~LoadPlugin();

        void loadPluginsFromDirectory(const std::string& directory);
        static std::vector<std::string> findPluginFiles(const std::string& directory);

    private:
        void loadPlugin(const std::string& filepath);
        std::vector<void*> _loadedLibraries;

        FactoryEntity& _factoryEntity;
        FactoryMaterial& _factoryMaterial;
    };
}
