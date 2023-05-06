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
             * @brief Loads all the plugins of a directory
             * 
             * This function will load all the plugins with the path given
             * The path given needs to be a directory path
             * 
             * @param directory string that define the path of the plugins 
             */
            void loadPluginsFromDirectory(const std::string& directory);
            /**
             * @brief Get the instance of the PluginLoader object
             */
            static PluginLoader& getInstance();


        private:
            /**
             * @brief Finds all plugin files in the given directory.
             * 
             * This function will search the specified directory for all files with the ".so" extension,
             * indicating that they are dynamic libraries containing plugins.
             * 
             * @param directory The path to the directory to search.
             */
            std::vector<std::string> findPluginFiles(const std::string& directory);

            /**
             * @brief Loads a single plugin from the specified file path.
             * 
             * This function will load a single plugin from the specified file path,
             * register its entities and materials with the factory, and add the plugin to the list of loaded plugins.
             * 
             * @param filepath The path to the plugin file.
             */
            void loadPlugin(const std::string& filepath);

            FactoryEntity& _factoryEntity;
            FactoryMaterial& _factoryMaterial;
            std::vector<std::unique_ptr<Plugin>> _loadedPlugins;
        };
}
