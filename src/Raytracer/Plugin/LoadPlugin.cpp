/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LoadPlugin
*/

#include <filesystem>
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

    std::cout << "Found " << pluginFiles.size() << " plugins" << std::endl;
    for (const auto& filepath : pluginFiles) {
        std::cout << "Loading plugin: " << filepath << std::endl;
        loadPlugin(filepath);
    }
}

std::vector<std::string> Raytracer::LoadPlugin::findPluginFiles(const std::string& directory)
{
    std::vector<std::string> pluginFiles;
    std::error_code errorCode;

    for (const auto& entry : std::filesystem::directory_iterator(directory, errorCode)) {
        std::string filename = entry.path().filename().string();
        if (filename.length() > 3 && filename.substr(filename.length() - 3) == ".so") {
            pluginFiles.push_back(entry.path().string());
        }
    }

    if (errorCode) {
        throw std::runtime_error("Failed to open directory: " + directory);
    }

    return pluginFiles;
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
        auto type = getResult<LibType>(library, "getType");

        switch (type) {
            case LibType::ENTITY: {
                auto createEntity = openLibraryFunc<Raytracer::IEntity*(*)(const libconfig::Setting&)>(library, "createEntity");
                auto destroyEntity = openLibraryFunc<void(*)(Raytracer::IEntity*)>(library, "destroyEntity");
                auto nameEntity = openLibraryFunc<const char*(*)()>(library, "getName");

                _factoryEntity.addCreator(nameEntity(), createEntity, destroyEntity);
                break;
            }
            case LibType::MATERIAL: {
                auto createMaterial = openLibraryFunc<Raytracer::IMaterial*(*)(const libconfig::Setting&)>(library, "createMaterial");
                auto destroyMaterial = openLibraryFunc<void(*)(Raytracer::IMaterial*)>(library, "destroyMaterial");
                auto nameMaterial = openLibraryFunc<const char*(*)()>(library, "getName");

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
