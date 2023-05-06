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
    /**
     * @brief The PluginLoader class
     * 
     * This class is used to load plugins contains inside the plugins directory
     */
    class PluginLoader {
        public:
            PluginLoader();
            ~PluginLoader();

            /**
             * @brief the function that load all the plugins of a directory
             * 
             * This function will load all the plugins with the path given
             * The path given needs to be a directory path
             * 
             * @param directory string that define the path of the plugins 
             */
            void loadPluginsFromDirectory(const std::string& directory);

        private:
            std::vector<std::string> findPluginFiles(const std::string& directory);
            void loadPlugin(const std::string& filepath);

            FactoryEntity& _factoryEntity;
            FactoryMaterial& _factoryMaterial;
            std::vector<std::unique_ptr<Plugin>> _loadedPlugins;
        };
}
