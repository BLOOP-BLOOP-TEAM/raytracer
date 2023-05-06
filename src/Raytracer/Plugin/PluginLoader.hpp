/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PluginLoader
*/

#pragma once

#include <string>
#include <dlfcn.h>
#include <map>
#include <functional>
#include <vector>
#include "IEntity.hpp"
#include "Plugin.hpp"
#include "FactoryEntity.hpp"
#include "FactoryMaterial.hpp"

namespace Raytracer {
    class PluginLoader {
    public:
        PluginLoader();
        ~PluginLoader();

        void loadPluginsFromDirectory(const std::string& directory);

        static PluginLoader& getInstance();

    private:
        std::vector<std::string> findPluginFiles(const std::string& directory);
        void loadPlugin(const std::string& filepath);

        FactoryEntity& _factoryEntity;
        FactoryMaterial& _factoryMaterial;
        std::vector<std::unique_ptr<Plugin>> _loadedPlugins;
    };
}
