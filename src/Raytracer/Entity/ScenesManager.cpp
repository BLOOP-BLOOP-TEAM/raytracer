/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ScenesManager
*/

#include "ScenesManager.hpp"

Raytracer::ScenesManager::ScenesManager() : _sceneActual(0)
{
}

void Raytracer::ScenesManager::addScene(std::shared_ptr<Scene> scene)
{
    _scenes.push_back(scene);
}

Raytracer::Scene &Raytracer::ScenesManager::getSceneActual() const
{
    return *_scenes[_sceneActual];
}

void Raytracer::ScenesManager::setSceneActual(int scene)
{
    _sceneActual = scene;
}

void Raytracer::ScenesManager::update(Raytracer::EventManager &eventManager)
{
    _scenes[_sceneActual]->update(eventManager);
}
