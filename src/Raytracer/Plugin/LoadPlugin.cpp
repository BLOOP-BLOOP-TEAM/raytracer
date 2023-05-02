/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LoadPlugin
*/

#include <dirent.h>
#include <dlfcn.h>
#include <iostream>
#include <stdexcept>
#include "LoadPlugin.hpp"
#include "Api.hpp"

Raytracer::LoadPlugin::LoadPlugin() : _factoryEntity(FactoryEntity::getInstance()), _factoryMaterial(FactoryMaterial::getInstance()) {}

Raytracer::LoadPlugin::~LoadPlugin()
{
    for (void* library : _loadedLibraries) {
        if (library) {
            dlclose(library);
        }
    }
}

void Raytracer::LoadPlugin::loadPluginsFromDirectory(const std::string& directory)
{
    auto pluginFiles = findPluginFiles(directory);
    for (const auto& filepath : pluginFiles) {
        loadPlugin(filepath);
    }
}

std::vector<std::string> Raytracer::LoadPlugin::findPluginFiles(const std::string& directory)
{
    std::vector<std::string> pluginFiles;
    DIR* dir = opendir(directory.c_str());
    if (dir) {
        struct dirent* entry;
        while ((entry = readdir(dir))) {
            std::string filename = entry->d_name;
            if (filename.length() > 3 && filename.substr(filename.length() - 3) == ".so") {
                pluginFiles.push_back(directory + "/" + filename);
            }
        }
        closedir(dir);
    } else {
        throw std::runtime_error("Failed to open directory: " + directory);
    }
    return pluginFiles;
}

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

void Raytracer::LoadPlugin::loadPlugin(const std::string& filepath)
{
    void* library = dlopen(filepath.c_str(), RTLD_NOW);

    if (!library) {
        std::cerr << "Failed to load plugin: " << filepath << "\n";
        std::cerr << "Error: " << dlerror() << "\n";
        return;
    }

    _loadedLibraries.push_back(library);

    try {
        LibType type = getResult<LibType>(library, "getType");

        switch (type) {
            case LibType::ENTITY: {
                auto createEntity = getResult<Raytracer::IEntity*(*)(const libconfig::Setting&)>(library, "CreateEntity");
                auto destroyEntity = getResult<void(*)(Raytracer::IEntity*)>(library, "destroyEntity");
                auto nameEntity = getResult<const char*(*)()>(library, "getName");

                _factoryEntity.addCreator(nameEntity(), createEntity, destroyEntity);
                break;
            }
            case LibType::MATERIAL: {
                auto createMaterial = getResult<Raytracer::IMaterial*(*)(const libconfig::Setting&)>(library, "CreateMaterial");
                auto destroyMaterial = getResult<void(*)(Raytracer::IMaterial*)>(library, "destroyMaterial");
                auto nameMaterial = getResult<const char*(*)()>(library, "getName");

                _factoryMaterial.addCreator(nameMaterial(), createMaterial, destroyMaterial);
                break;
            }
            default:
                std::cerr << "Unknown plugin type in plugin: " << filepath << "\n";
                break;
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Failed to load symbols in plugin: " << filepath << "\n";
        std::cerr << "Error: " << e.what() << "\n";
    }
}
