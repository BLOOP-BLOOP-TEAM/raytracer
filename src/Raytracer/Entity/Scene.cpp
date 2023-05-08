/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Scene
*/

#include <utility>
#include "Scene.hpp"
#include "FactoryEntity.hpp"
#include "FactoryMaterial.hpp"
#include "Image.hpp"

static const std::string FOLDER_PPM = "./PPM/";

Component::Vector3f Raytracer::Scene::getResolution() const
{
    for (IEntity* entity : _entities) {
        if (entity->getType() == Raytracer::CompType::CAM)
            return (dynamic_cast<ICam*>(entity))->getResolution();
    }
    return Component::Vector3f(1920, 1080, 0);
}

Raytracer::Scene::Scene(const std::string &name, const std::string &nameFile) : _image(std::make_unique<Image>(getResolution().x, getResolution().y)), _fileName(nameFile), _isCalculate(
        false), _name(name)
{
    std::cout << "Creating scene" << std::endl;
}

Raytracer::Scene::~Scene()
{
    FactoryEntity& factoryEntity = FactoryEntity::getInstance();
    FactoryMaterial& factoryMaterial = FactoryMaterial::getInstance();

    std::cout << "Destroying scene" << std::endl;
    for (IEntity* entity : _entities) {
        if (entity)
            factoryEntity.destroyEntity(entity);
    }

    for (IMaterial* material : _materials) {
        if (material)
            factoryMaterial.destroyMaterial(material);
    }
}

void Raytracer::Scene::calculateImage()
{
    _image->calculateImage(_entities);
    _image->writePPM(FOLDER_PPM + _name + ".ppm");
    setIsCalculate();
}

void Raytracer::Scene::addEntity(IEntity *entity)
{
    _entities.push_back(entity);
}

void Raytracer::Scene::addMaterial(IMaterial *material)
{
    _materials.push_back(material);
}

Raytracer::IEntity &Raytracer::Scene::getEntity(int index) const
{
    if (index < 0 || index >= _entities.size())
        throw std::out_of_range("Index out of range");
    return *_entities[index];
}

const std::vector<Raytracer::IEntity *> &Raytracer::Scene::getEntities() const
{
    return _entities;
}

Raytracer::IMaterial &Raytracer::Scene::getMaterial(int index) const
{
    if (index < 0 || index >= _materials.size())
        throw std::out_of_range("Index out of range");
    return *_materials[index];
}

const std::vector<Raytracer::IMaterial *> &Raytracer::Scene::getMaterials() const
{
    return _materials;
}

Raytracer::Image &Raytracer::Scene::getImage() const
{
    return *_image;
}

void Raytracer::Scene::update(Raytracer::EventManager &eventManager)
{
}

const std::string &Raytracer::Scene::getFileName()
{
    return _fileName;
}

void Raytracer::Scene::setIsCalculate()
{
    _isCalculate = !_isCalculate;
}

const bool &Raytracer::Scene::getIsCalculate() const
{
    return _isCalculate;
}
