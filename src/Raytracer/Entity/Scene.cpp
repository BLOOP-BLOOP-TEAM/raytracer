/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Scene
*/

#include "Scene.hpp"
#include "Image.hpp"

static const std::string FOLDER_PPM = "./PPM/";

Raytracer::Scene::Scene(const std::string &name) : _image(std::make_unique<Image>(1920, 1080)), _fileName(name) 
{
}

Raytracer::Scene::~Scene()
{
}

void Raytracer::Scene::calculateImage()
{
    _image->calculateImage(_entities);
    _image->write_ppm(FOLDER_PPM + _fileName + ".ppm");
    setIsCalculate();
}

void Raytracer::Scene::addEntity(IEntity *entity)
{
    _entities.push_back(entity);
}

Raytracer::IEntity &Raytracer::Scene::getEntity(int index) const
{
    if (index < 0 || index >= _entities.size())
        throw std::out_of_range("Index out of range");
    return *_entities[index];
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

const bool &Raytracer::Scene::getIsCalculate()
{
    return _isCalculate;
}
