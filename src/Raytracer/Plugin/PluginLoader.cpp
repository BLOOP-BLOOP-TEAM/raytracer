/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PluginLoader
*/

#include <filesystem>
#include <iostream>
#include <stdexcept>
#include "PluginLoader.hpp"
#include "Api.hpp"

Raytracer::PluginLoader::PluginLoader() {
    std::cout << "Loading plugins from directory: "  << std::endl;
}

Raytracer::PluginLoader::~PluginLoader()
{
    std::cout << "Unloading plugins" << std::endl;
}

void Raytracer::PluginLoader::loadPluginsFromDirectory(const std::string& directory)
{
    auto pluginFiles = findPluginFiles(directory);

    std::cout << "Found " << pluginFiles.size() << " plugins" << std::endl;
    for (const auto& filepath : pluginFiles) {
        std::cout << "Loading plugin: " << filepath << std::endl;
        loadPlugin(filepath);
    }
}

std::vector<std::string> Raytracer::PluginLoader::findPluginFiles(const std::string& directory)
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

void Raytracer::PluginLoader::loadPlugin(const std::string& filepath)
{
    try {
        auto plugin = std::make_unique<Plugin>(filepath);
        LibType type = plugin->getFunction<LibType(*)()>("getType")();

        switch (type) {
            case LibType::ENTITY: {
                auto createEntity = plugin->getFunction<Raytracer::IEntity*(*)(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>("createEntity");
                auto destroyEntity = plugin->getFunction<void(*)(Raytracer::IEntity*)>("destroyEntity");
                auto nameEntity = plugin->getFunction<const char*(*)()>("getName");

                FactoryEntity::getInstance().addCreator(nameEntity(), createEntity, destroyEntity);
                break;
            }
            case LibType::MATERIAL: {
                auto createMaterial = plugin->getFunction<Raytracer::IMaterial*(*)(const std::map<std::string, std::variant<double, int, std::string, bool>>&)>("createMaterial");
                auto destroyMaterial = plugin->getFunction<void(*)(Raytracer::IMaterial*)>("destroyMaterial");
                auto nameMaterial = plugin->getFunction<const char*(*)()>("getName");

                FactoryMaterial::getInstance().addCreator(nameMaterial(), createMaterial, destroyMaterial);
                break;
            }
            case LibType::SKYBOX: {
                auto createSkybox = plugin->getFunction<Raytracer::ISkybox*(*)(const std::map<std::string, std::variant<double, int, std::string, bool>>&)>("createSkybox");
                auto destroySkybox = plugin->getFunction<void(*)(Raytracer::ISkybox*)>("destroySkybox");
                auto nameSkybox = plugin->getFunction<const char*(*)()>("getName");

                FactorySkybox::getInstance().addCreator(nameSkybox(), createSkybox, destroySkybox);
                break;
            }
            default:
                std::cerr << "Unknown plugin type in plugin: " << filepath << "\n";
                break;
        }

        _loadedPlugins.push_back(std::move(plugin));
    } catch (const std::runtime_error& e) {
        std::cerr << "Failed to load plugin: " << filepath << "\n";
        std::cerr << "Error: " << e.what() << "\n";
    }
}

Raytracer::PluginLoader&  Raytracer::PluginLoader::getInstance()
{
    static Raytracer::PluginLoader instance;

    return instance;
}
