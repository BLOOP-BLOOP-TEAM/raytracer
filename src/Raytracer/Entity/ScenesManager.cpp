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

void Raytracer::ScenesManager::removeScene(const std::string &path)
{
    unsigned int scenesSize = _scenes.size();

    for (unsigned int i = 0; i < scenesSize; i++) {
        if (_scenes[i]->getFileName() == path) {
            _scenes.erase(_scenes.begin() + i);
            return;
        }
    }
    throw Raytracer::RaytracerException("Scene not found");
}

void Raytracer::ScenesManager::replaceScene(std::unique_ptr<Scene> newScene, const std::string &path)
{
    unsigned int scenesSize = _scenes.size();

    for (unsigned int i = 0; i < scenesSize; i++) {
        if (_scenes[i]->getFileName() == path) {
            _scenes[i] = std::move(newScene);
            return;
        }
    }
    throw Raytracer::RaytracerException("Scene not found");
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
