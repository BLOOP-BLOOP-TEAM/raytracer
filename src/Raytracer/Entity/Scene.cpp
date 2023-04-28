/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Scene
*/

#include "Scene.hpp"
#include "Image.hpp"

Raytracer::Scene::Scene() : _image(std::make_unique<Image>(1920, 1080))
{
}

Raytracer::Scene::~Scene()
{
    
}

void Raytracer::Scene::calculateImage()
{
    _image->calculateImage(_entities);
}

void Raytracer::Scene::addEntity(std::shared_ptr<IEntity> entity)
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
