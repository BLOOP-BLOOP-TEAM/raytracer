/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LoadConfig
*/

#include <iostream>
#include <filesystem>
#include "LoadConfig.hpp"

static const std::string FOLDER_NAME = "Scenes";

static const std::string PRIMITIVES = "primitives";
static const std::string CAMERA = "camera";
static const std::string LIGHTS = "lights";

Raytracer::LoadConfig::LoadConfig()
{
    _factories[PRIMITIVES] = std::make_shared<Raytracer::FactoryEntity>();
    _factories[CAMERA] = std::make_shared<Raytracer::FactoryEntity>();
    _factories[LIGHTS] = std::make_shared<Raytracer::FactoryEntity>();
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

void Raytracer::LoadConfig::loadConfigFile(const std::string &path)
{
    libconfig::Config cfg;

    try {
        cfg.readFile(path.c_str());
        std::cout << "File found : " << path << std::endl;
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        return;
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        return;
    }
    const libconfig::Setting &root = cfg.getRoot();
    // Output a list of all books in the inventory.
    try {
        const libconfig::Setting &books = root;
        int count = books.getLength();

        for (int i = 0; i < count; i++) {
            const libconfig::Setting &book = books[i];
            std::cout << book.getName() << std::endl << std::endl;

            if (book.getName() == PRIMITIVES)
                loadPrimitives(book);
            else
                loadPluginType(book.getName(), book);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        // Ignore.
    }
}

void Raytracer::LoadConfig::loadPluginType(const std::string &type, const libconfig::Setting &root)
{
    if (_factories.find(type) == _factories.end()) {
        std::cerr << "configLoader: loadPlugintypes: plugin type not found" << std::endl;
        return;
    }
    _factories[type]->createEntity(type, root);
}

void Raytracer::LoadConfig::loadPrimitives(const libconfig::Setting &root)
{
    if (_factories.find(PRIMITIVES) == _factories.end()) {
        std::cerr << "configLoader: loadPrimitives: plugin type not found" << std::endl;
        return;
    }
    try {
        const libconfig::Setting &primitives = root[PRIMITIVES];
        int count = primitives.getLength();

        for (int i = 0; i < count; i++) {
            const libconfig::Setting &primitive = primitives[i];
            std::cout << primitive.getName() << std::endl << std::endl;
            _factories[PRIMITIVES]->createEntity(primitive.getName(), primitive);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        // Ignore.
    }
}
