/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LoadPlugin
*/

#pragma once

#include <string>
#include <dlfcn.h>
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
        LoadPlugin& operator=(const LoadPlugin&) = delete;
        static LoadPlugin& getInstance();

    private:
        static std::vector<std::string> findPluginFiles(const std::string& directory);
        void loadPlugin(const std::string& filepath);

        template <typename T, typename... Args>
        T getResult(void* library, const std::string& symbolName, Args&&... args)
        {
            void* sym = dlsym(library, symbolName.c_str());

            if (!sym) {
                throw std::runtime_error("Error on open with dlsym: " + std::string(dlerror()));
            }

            T (*function)(Args...) = reinterpret_cast<T(*)(Args...)>(sym);
            return (function(std::forward<Args>(args)...));
        }

        template <typename T>
        T openLibraryFunc(void *library, const std::string &symbolName)
        {
            void *sym = dlsym(library, symbolName.c_str());

            if (!sym) {
                throw std::runtime_error("Error on open with dlsym: " + std::string(dlerror()));
            }

            return reinterpret_cast<T>(sym);
        }

        std::vector<void*> _loadedLibraries;
        FactoryEntity& _factoryEntity;
        FactoryMaterial& _factoryMaterial;
    };
}
