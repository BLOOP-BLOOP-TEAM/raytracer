/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ScenesManager
*/

#include "RaytracerException.hpp"
#include "ScenesManager.hpp"

Raytracer::ScenesManager::ScenesManager() : _sceneActual(0)
{
}

void Raytracer::ScenesManager::addScene(std::unique_ptr<Scene> scene)
{
    _scenes.push_back(std::move(scene));
}

void Raytracer::ScenesManager::addMultipleScenes(std::vector<std::unique_ptr<Scene>> scenes)
{
    for (auto &scene : scenes)
        _scenes.push_back(std::move(scene));
}

Raytracer::Scene &Raytracer::ScenesManager::getSceneActual() const
{
    if (_sceneActual < 0 || _sceneActual >= _scenes.size())
        throw Raytracer::RaytracerException("Scene actual is not valid");
    return *_scenes[_sceneActual];
}

void Raytracer::ScenesManager::setSceneActual(int scene)
{
    _sceneActual = scene;
}

void Raytracer::ScenesManager::update(Raytracer::EventManager &eventManager)
{
    // treatment of events
    // if is event triggered change scene _sceneActual + 1
    if (!_scenes[_sceneActual]->getIsCalculate())
        _scenes[_sceneActual]->calculateImage();
    _scenes[_sceneActual]->update(eventManager);
}
