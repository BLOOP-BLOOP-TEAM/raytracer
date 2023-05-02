/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LoadConfig
*/

#include <iostream>
#include <filesystem>
#include <vector>
#include "IEntity.hpp"
#include "LoadConfig.hpp"

static const std::string FOLDER_NAME = "Scenes";

static const std::string PRIMITIVES = "primitives";
static const std::string CAMERA = "camera";
static const std::string LIGHTS = "lights";
static const std::string MATERIALS = "materials";

static const std::vector<std::string> elementTypes = {
    PRIMITIVES,
    CAMERA,
    LIGHTS,
    MATERIALS
};

Raytracer::LoadConfig::LoadConfig()
{
    loadConfigFolder();
}

bool Raytracer::LoadConfig::isAGoodConfigFile(libconfig::Config &cfg, const std::string &path)
{
    try {
        cfg.readFile(path.c_str());
        std::cout << "File found : " << path << std::endl;
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        return false;
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        return false;
    }
    return true;
}

void Raytracer::LoadConfig::loadConfigFolder()
{
    for (const auto &entry : std::filesystem::directory_iterator(FOLDER_NAME)) {
        // check if filename end with .cgf
        if (entry.path().filename().extension() != ".cfg")
            continue;
        loadConfigFile(entry.path());
    }
}

void Raytracer::LoadConfig::loadPluginType(const std::string &type, const libconfig::Setting &root, Raytracer::Scene &scene)
{
    if (type == PRIMITIVES)
        loadPrimitives(root);
    else if (type == MATERIALS)
        loadMaterials(root);
    else if (std::find(elementTypes.begin(), elementTypes.end(), type) != elementTypes.end())
        _factoryEntity.createEntity(type, root);
    else
        std::cerr << "configLoader: loadPlugintypes: plugin type not found" << std::endl;
}

std::unique_ptr<Raytracer::Scene> Raytracer::LoadConfig::loadConfigFile(const std::string &path)
{
    libconfig::Config cfg;
    std::unique_ptr<Raytracer::Scene> scene = std::make_unique<Raytracer::Scene>();

    if (!isAGoodConfigFile(cfg, path))
        return nullptr;
    const libconfig::Setting &root = cfg.getRoot();
    // Output a list of all books in the inventory.
    try {
        const libconfig::Setting &elements = root;
        int count = elements.getLength();

        for (int i = 0; i < count; i++) {
            const libconfig::Setting &element = elements[i];

            std::cout << element.getName() << std::endl << std::endl;
            loadPluginType(element.getName(), element, *scene);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        // Ignore.
    }
    return scene;
}

std::vector<Raytracer::IEntity *> Raytracer::LoadConfig::loadPrimitives(const libconfig::Setting &root)
{
    std::vector<Raytracer::IEntity *> primitivesEntities;

    try {
        const libconfig::Setting &primitives = root[PRIMITIVES];
        int count = primitives.getLength();

        for (int i = 0; i < count; i++) {
            const libconfig::Setting &primitive = primitives[i];
            std::cout << primitive.getName() << std::endl << std::endl;
            _factoryEntity.createEntity(primitive.getName(), primitive);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        // Ignore.
    }
    return primitivesEntities;
}

void Raytracer::LoadConfig::loadMaterials(const libconfig::Setting &root)
{
    try {
        const libconfig::Setting &materials = root[MATERIALS];
        int count = materials.getLength();

        for (int i = 0; i < count; i++) {
            const libconfig::Setting &material = materials[i];
            std::cout << material.getName() << std::endl << std::endl;
            _factoryMaterial.createMaterial(material.getName(), material);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        // Ignore.
    }
}
