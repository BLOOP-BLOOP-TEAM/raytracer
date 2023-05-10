/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ConfigLoader
*/

#include <filesystem>
#include <iomanip>
#include <variant>
#include <vector>
#include "AMaterial.hpp"
#include "IEntity.hpp"
#include "APrimitive.hpp"
#include "RaytracerException.hpp"
#include "ConfigLoader.hpp"

static const std::string FOLDER_NAME = "Scenes";
static const std::string SKYBOX = "skybox";
static const std::string PRIMITIVES = "primitives";
static const std::string CAMERA = "camera";
static const std::string LIGHTS = "lights";
static const std::string MATERIALS = "materials";
static const std::string MATERIAL = "material";
static const std::string NAME = "name";

static const std::vector<std::string> elementTypes = {
    PRIMITIVES,
    CAMERA,
    LIGHTS,
    MATERIALS
};

bool Raytracer::ConfigLoader::isAGoodConfigFile(libconfig::Config &cfg, const std::string &path)
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

std::map<std::string, std::variant<double, int, std::string, bool>> Raytracer::ConfigLoader::transformSettingToDataMap(const libconfig::Setting &setting)
{
    std::map<std::string, std::variant<double, int, std::string, bool>> dataMap;
    std::string name;
    std::variant<double, int, std::string, bool> data;
    std::string stringValue;

    for (auto &element : setting) {
        name = element.getName();
        switch (element.getType()) {
            case libconfig::Setting::Type::TypeInt:
                int intValue;
                setting.lookupValue(name, intValue);
                data = intValue;
                break;
            case libconfig::Setting::Type::TypeFloat:
                double doubleValue;
                setting.lookupValue(name, doubleValue);
                data = doubleValue;
                break;
            case libconfig::Setting::Type::TypeString:
                setting.lookupValue(name, stringValue);
                data = stringValue;
                break;
            case libconfig::Setting::Type::TypeBoolean:
                bool boolValue;
                setting.lookupValue(name, boolValue);
                data = boolValue;
                break;
            default:
                throw Raytracer::RaytracerException("Unknown type in config file");
        }
        dataMap[name] = data;
    }
    return dataMap;
}


std::unique_ptr<std::vector<std::unique_ptr<Raytracer::Scene>>> Raytracer::ConfigLoader::loadConfigFolder()
{
    std::unique_ptr<std::vector<std::unique_ptr<Raytracer::Scene>>> scenes = std::make_unique<std::vector<std::unique_ptr<Raytracer::Scene>>>();
    std::unique_ptr<Raytracer::Scene> scene;

    for (const auto &entry : std::filesystem::directory_iterator(FOLDER_NAME)) {
        if (entry.path().filename().extension() != ".cfg")
            continue;
        scene = loadConfigFile(entry.path());
        if (scene != nullptr)
            scenes->push_back(std::move(scene));
    }
    std::cout << "ConfigLoader: " << scenes->size() << " scenes loaded" << std::endl;
    return scenes;
}

void Raytracer::ConfigLoader::loadPluginType(const std::string &type, const libconfig::Setting &root, Raytracer::Scene &scene, std::map<std::pair<std::string, IEntity *>, std::pair<std::string, IMaterial *>> &materialsToApply)
{
    if (type == PRIMITIVES)
        loadPrimitives(root, scene, materialsToApply);
    else if (type == MATERIALS)
        loadMaterials(root, scene, materialsToApply);
    else if (type == LIGHTS)
        loadLights(root, scene);
    else if (type == SKYBOX)
        loadSkybox(root, scene);
    else if (std::find(elementTypes.begin(), elementTypes.end(), type) != elementTypes.end()) {
        std::cout << "ConfigLoader: loading " << type << std::endl;
        scene.addEntity(Raytracer::FactoryEntity::getInstance().createEntity(type, transformSettingToDataMap(root)));
    } else
        std::cerr << "configLoader: loadPlugintypes: plugin type not found" << std::endl;
}

void Raytracer::ConfigLoader::applyMaterialsToPrimitives(std::map<std::pair<std::string, IEntity *>, std::pair<std::string, IMaterial *>> &materialsToApply)
{
    IMaterial *material;
    APrimitive *primitive;

    for (auto &element : materialsToApply) {
        primitive = dynamic_cast<APrimitive *>(element.first.second);
        material = element.second.second;
        std::cout << "ConfigLoader: applying material " << element.second.first << " to primitive " << element.first.first << std::endl;
        primitive->setMaterial(material);
    }
}

std::string Raytracer::ConfigLoader::extractFileName(const std::string& path)
{
    std::filesystem::path fsPath(path);
    std::string fileName = fsPath.stem().string();
    return fileName;
}

std::unique_ptr<Raytracer::Scene> Raytracer::ConfigLoader::loadConfigFile(const std::string &path)
{
    libconfig::Config cfg;
    std::unique_ptr<Raytracer::Scene> scene;
    std::map<std::pair<std::string, IEntity *>, std::pair<std::string, IMaterial *>> materialsToApply;

    if (!isAGoodConfigFile(cfg, path))
        return nullptr;
    const libconfig::Setting &root = cfg.getRoot();
    scene = std::make_unique<Raytracer::Scene>(extractFileName(path), path);
    try {
        const libconfig::Setting &elements = root;
        int count = elements.getLength();

        for (int i = 0; i < count; i++) {
            const libconfig::Setting &element = elements[i];

            std::cout << "Element found : " << element.getName() << std::endl;
            loadPluginType(element.getName(), element, *scene, materialsToApply);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "configLoader: loadConfigFile: Setting not found: " << nfex.what() << std::endl;
        return nullptr;
    } catch (const libconfig::SettingTypeException &tex) {
        std::cerr << "configLoader: loadConfigFile: Setting type mismatch: " << tex.what() << std::endl;
        return nullptr;
    } catch (const libconfig::SettingException &ex) {
        std::cerr << "configLoader: loadConfigFile: Setting exception: " << ex.what() << std::endl;
        return nullptr;
    } catch (const std::exception &e) {
        std::cerr << "configLoader: loadConfigFile: exception: " << e.what() << std::endl;
        return nullptr;
    }
    try {
        applyMaterialsToPrimitives(materialsToApply);
    } catch (const std::exception &e) {
        std::cerr << "configLoader: loadConfigFile: exception: " << e.what() << std::endl;
        return nullptr;
    }
    if (!scene) {
        return nullptr;
    }
    std::cout << "SCENE CREATED" << std::endl;
    return scene;
}

void Raytracer::ConfigLoader::loadPrimitives(const libconfig::Setting &root, Raytracer::Scene &scene, std::map<std::pair<std::string, IEntity *>, std::pair<std::string, IMaterial *>> &materialsToApply)
{
    const libconfig::Setting &primitives = root;
    IEntity *entity = nullptr;
    int count = primitives.getLength();

    for (int i = 0; i < count; i++) {
        const libconfig::Setting &primitive = primitives[i];

        std::cout << "\tPrimitive found : " << primitive.getName() << std::endl;
        for (const auto &element : primitive) {
            if (!element.exists(MATERIAL))
                throw Raytracer::RaytracerException("ConfigLoader: loadPrimitives: material not found");
            entity = Raytracer::FactoryEntity::getInstance().createEntity(primitive.getName(), transformSettingToDataMap(element));
            std::cout << "ConfigLoader: loading " << primitive.getName() << std::endl;
            std::string name = element[NAME];
            std::cout << "ConfigLoader: loading " << name << std::endl;
            materialsToApply.insert({{element[NAME], entity}, {element[MATERIAL], nullptr}});
            scene.addEntity(entity);
        }
    }
}

void Raytracer::ConfigLoader::loadLights(const libconfig::Setting &root, Raytracer::Scene &scene)
{
    const libconfig::Setting &lights = root;
    int count = lights.getLength();

    for (int i = 0; i < count; i++) {
        const libconfig::Setting &light = lights[i];

        std::cout << "\tLight found : " << light.getName() << std::endl;
        for (const auto &element : light) {
            scene.addEntity(Raytracer::FactoryEntity::getInstance().createEntity(light.getName(), transformSettingToDataMap(element)));
        }
    }
}

void Raytracer::ConfigLoader::addMaterialInMap(std::map<std::pair<std::string, IEntity *>, std::pair<std::string, IMaterial *>> &materialsToApply, const std::string &name, Raytracer::IMaterial *material)
{
    for (auto &element : materialsToApply) {
        if (element.second.first == name) {
            element.second.second = material;
        }
    }
}

void Raytracer::ConfigLoader::loadMaterials(const libconfig::Setting &root, Raytracer::Scene &scene, std::map<std::pair<std::string, IEntity *>, std::pair<std::string, IMaterial *>> &materialsToApply)
{
    const libconfig::Setting &materials = root;
    int count = materials.getLength();

    std::cout << "Materials found : " << count << std::endl;
    for (int i = 0; i < count; i++) {
        const libconfig::Setting &material = materials[i];

        std::cout << "\tMaterial found : " << material.getName() << std::endl;
        for (const auto &element : material) {
            std::cout << "ConfigLoader: loading material " << material.getName() << std::endl;
            std::string name = element["name"];
            std::cout << "ConfigLoader: loading material " << name << std::endl;
            IMaterial *mat = Raytracer::FactoryMaterial::getInstance().createMaterial(material.getName(), transformSettingToDataMap(element));
            addMaterialInMap(materialsToApply, name, mat);
            scene.addMaterial(mat);
        }
    }
}

void Raytracer::ConfigLoader::loadSkybox(const libconfig::Setting &root, Raytracer::Scene &scene)
{
    const libconfig::Setting &skybox = root;

    std::cout << "\tSkybox found : " << skybox.getName() << std::endl;
    for (const auto &skyboxElement : skybox) {
        std::cout << "ConfigLoader: loading skybox " << skyboxElement.getName() << std::endl;
        for (const auto &element : skyboxElement) {
            std::cout << "ConfigLoader: loading skybox " << skybox.getName()
                      << std::endl;
            scene.addSkybox(
            Raytracer::FactorySkybox::getInstance().createSkybox(
            skyboxElement.getName(), transformSettingToDataMap(element)));
        }
    }
}
