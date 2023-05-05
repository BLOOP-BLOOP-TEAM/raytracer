/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ScenesManager
*/

#include "RaytracerException.hpp"
#include "ScenesManager.hpp"

static const std::string keyLeft = "KEY_LEFT_PRESSED";
static const std::string keyRight = "KEY_RIGHT_PRESSED";

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
    if (eventManager.isEventTriggered(keyLeft)) {
        _sceneActual - 1 >= 0 ? setSceneActual(_sceneActual - 1) : 
                                setSceneActual(_scenes.size());
    }
    if (eventManager.isEventTriggered(keyRight)) {
        _sceneActual + 1 > _scenes.size() ? setSceneActual(0) :
                                            setSceneActual(_sceneActual + 1);
    }
    if (!_scenes[_sceneActual]->getIsCalculate())
        _scenes[_sceneActual]->calculateImage();
    _scenes[_sceneActual]->update(eventManager);
}
