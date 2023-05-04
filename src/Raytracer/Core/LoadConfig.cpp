/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LoadConfig
*/

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
    std::cout << "File is a good config file" << std::endl;
    return true;
}

std::vector<std::unique_ptr<Raytracer::Scene>> Raytracer::LoadConfig::loadConfigFolder()
{
    std::vector<std::unique_ptr<Raytracer::Scene>> scenes;
    std::unique_ptr<Raytracer::Scene> scene;

    for (const auto &entry : std::filesystem::directory_iterator(FOLDER_NAME)) {
        // check if filename end with .cgf
        if (entry.path().filename().extension() != ".cfg")
            continue;
        scene = loadConfigFile(entry.path());
        if (scene != nullptr)
            scenes.push_back(std::move(scene));
    }
    return scenes;
}

void Raytracer::LoadConfig::loadPluginType(const std::string &type, const libconfig::Setting &root, Raytracer::Scene &scene, std::map<std::string, std::string> &materialsToApply)
{
    if (type == PRIMITIVES)
        loadPrimitives(root, scene, materialsToApply);
    else if (type == MATERIALS)
        loadMaterials(root, scene);
    else if (type == LIGHTS)
        loadLights(root, scene);
    else if (std::find(elementTypes.begin(), elementTypes.end(), type) != elementTypes.end()) {
        std::cout << "LoadConfig: loading " << type << std::endl;
        try {
            scene.addEntity(Raytracer::FactoryEntity::getInstance().createEntity(type, root));
        } catch (const std::exception &e) {
            std::cerr << "LoadConfig: " << e.what() << std::endl;
        }
    } else
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
    } catch (const libconfig::SettingTypeException &tex) {
        std::cerr << "configLoader: loadConfigFile: " << tex.what() << " : " << tex.getPath() << std::endl;
    } catch (const libconfig::SettingException &ex) {
        std::cerr << "configLoader: loadConfigFile: " << ex.what() << std::endl;
    }
    applyMaterialsToPrimitives(*scene, materialsToApply);
    return scene;
}

void Raytracer::LoadConfig::loadPrimitives(const libconfig::Setting &root, Raytracer::Scene &scene, std::map<std::string, std::string> &materialsToApply)
{
    try {
        const libconfig::Setting &primitives = root;
        int count = primitives.getLength();

        for (int i = 0; i < count; i++) {
            const libconfig::Setting &primitive = primitives[i];

            std::cout << "\tPrimitive found : " << primitive.getName() << std::endl;
            for (const auto &element : primitive) {
                if (element.exists(MATERIAL))
                    materialsToApply.insert({primitive.getName(), element[MATERIAL]});
                std::cout << "LoadConfig: loading " << primitive.getName() << std::endl;
                scene.addEntity(Raytracer::FactoryEntity::getInstance().createEntity(primitive.getName(), element));
            }
        }
    } catch (const libconfig::SettingException &ex) {
        std::cerr << "configLoader: loadPrimitives: " << ex.what() << " : " << ex.getPath() << std::endl;
    }
}

void Raytracer::LoadConfig::loadLights(const libconfig::Setting &root, Raytracer::Scene &scene)
{
    try {
        const libconfig::Setting &lights = root;
        int count = lights.getLength();

        for (int i = 0; i < count; i++) {
            const libconfig::Setting &light = lights[i];

            std::cout << "\tLight found : " << light.getName() << std::endl;
            for (const auto &element : light) {
                scene.addEntity(Raytracer::FactoryEntity::getInstance().createEntity(light.getName(), element));
            }
        }
    } catch (const libconfig::SettingException &ex) {
        std::cerr << "configLoader: loadLights: " << ex.what() << " : " << ex.getPath() << std::endl;
    }
}

void Raytracer::LoadConfig::loadMaterials(const libconfig::Setting &root, Raytracer::Scene &scene)
{
    try {
        const libconfig::Setting &materials = root;
        int count = materials.getLength();

        std::cout << "Materials found : " << count << std::endl;
        for (int i = 0; i < count; i++) {
            const libconfig::Setting &material = materials[i];

            std::cout << "\tMaterial found : " << material.getName() << std::endl;
            for (const auto &element : material) {
                std::cout << "LoadConfig: new entity" << std::endl;
                scene.addMaterial(Raytracer::FactoryMaterial::getInstance().createMaterial(material.getName(), element));
            }
        }
    } catch (const libconfig::SettingException &ex) {
        std::cerr << "configLoader: loadMaterials: " << ex.what() << " : " << ex.getPath() << std::endl;
    }
}
