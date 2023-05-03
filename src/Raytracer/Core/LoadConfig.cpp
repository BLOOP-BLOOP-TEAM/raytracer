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
#include "APrimitive.hpp"
#include "LoadConfig.hpp"

static const std::string FOLDER_NAME = "Scenes";

static const std::string PRIMITIVES = "primitives";
static const std::string CAMERA = "camera";
static const std::string LIGHTS = "lights";
static const std::string MATERIALS = "materials";
static const std::string MATERIAL = "material";

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

std::vector<std::unique_ptr<Raytracer::Scene>> Raytracer::LoadConfig::loadConfigFolder()
{
    std::vector<std::unique_ptr<Raytracer::Scene>> scenes;

    for (const auto &entry : std::filesystem::directory_iterator(FOLDER_NAME)) {
        // check if filename end with .cgf
        if (entry.path().filename().extension() != ".cfg")
            continue;
        scenes.push_back(loadConfigFile(entry.path()));
    }
    return scenes;
}

void Raytracer::LoadConfig::loadPluginType(const std::string &type, const libconfig::Setting &root, Raytracer::Scene &scene, std::map<std::string, std::string> &materialsToApply)
{
    if (type == PRIMITIVES)
        loadPrimitives(root, scene, materialsToApply);
    else if (type == MATERIALS)
        loadMaterials(root, scene);
    else if (std::find(elementTypes.begin(), elementTypes.end(), type) != elementTypes.end())
        scene.addEntity(Raytracer::FactoryEntity::getInstance().createEntity(type, root));
    else
        std::cerr << "configLoader: loadPlugintypes: plugin type not found" << std::endl;
}

Raytracer::IMaterial *Raytracer::LoadConfig::getMaterialFromName(const Raytracer::Scene &scene, const std::string &name)
{
    for (auto &element : scene.getMaterials()) {
        auto material = static_cast<Raytracer::IMaterial *>(element);
        auto materialType = static_cast<Raytracer::AMaterial *>(material)->getType();

        if (materialType == name)
            return material;
    }
    return nullptr;
}

void Raytracer::LoadConfig::applyMaterialsToPrimitives(Raytracer::Scene &scene, std::map<std::string, std::string> &materialsToApply)
{
    Raytracer::IMaterial *material = nullptr;

    for (auto &element : scene.getEntities()) {
        if (element->getType() != Raytracer::CompType::PRIMITIVE) {
            continue;
        }
        auto primitive = static_cast<Raytracer::APrimitive *>(element);

        if (materialsToApply.find(primitive->getTypePrimitive()) != materialsToApply.end()) {
            material = getMaterialFromName(scene, materialsToApply[primitive->getTypePrimitive()]);
            if (material != nullptr)
                primitive->setMaterial(material);
        }
    }
}

std::unique_ptr<Raytracer::Scene> Raytracer::LoadConfig::loadConfigFile(const std::string &path)
{
    libconfig::Config cfg;
    std::unique_ptr<Raytracer::Scene> scene;
    std::map<std::string, std::string> materialsToApply;

    if (!isAGoodConfigFile(cfg, path))
        return nullptr;
    const libconfig::Setting &root = cfg.getRoot();
    scene = std::make_unique<Raytracer::Scene>(path);
    // Output a list of all books in the inventory.
    try {
        const libconfig::Setting &elements = root;
        int count = elements.getLength();

        for (int i = 0; i < count; i++) {
            const libconfig::Setting &element = elements[i];

            std::cout << "Element found : " << element.getName() << std::endl;
            loadPluginType(element.getName(), element, *scene, materialsToApply);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        // Ignore.
    }
    applyMaterialsToPrimitives(*scene, materialsToApply);
    return scene;
}

void Raytracer::LoadConfig::loadPrimitives(const libconfig::Setting &root, Raytracer::Scene &scene, std::map<std::string, std::string> &materialsToApply)
{
    try {
        const libconfig::Setting &primitives = root[PRIMITIVES];
        int count = primitives.getLength();

        for (int i = 0; i < count; i++) {
            const libconfig::Setting &primitive = primitives[i];

            std::cout << primitive.getName() << std::endl << std::endl;
            if (primitive.exists(MATERIAL))
                materialsToApply.insert({primitive.getName(), primitive[MATERIAL]});
            scene.addEntity(Raytracer::FactoryEntity::getInstance().createEntity(primitive.getName(), primitive));
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        // Ignore.
    }
}

void Raytracer::LoadConfig::loadMaterials(const libconfig::Setting &root, Raytracer::Scene &scene)
{
    try {
        const libconfig::Setting &materials = root[MATERIALS];
        int count = materials.getLength();

        for (int i = 0; i < count; i++) {
            const libconfig::Setting &material = materials[i];

            std::cout << material.getName() << std::endl << std::endl;
            scene.addMaterial(Raytracer::FactoryMaterial::getInstance().createMaterial(material.getName(), material));
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        // Ignore.
    }
}
