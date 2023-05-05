/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Core
*/

#include "Core.hpp"

static const std::string FOLDER = "./plugins";

Raytracer::Core::Core() : _scenesManager(), _displayModule(1920, 1080, "Raytracer"), _eventManager(_displayModule.getWindow()), _observer()
{
    LoadPlugin loadPlugin;
    LoadConfig LoadConfig;

    loadPlugin.loadPluginsFromDirectory(FOLDER);
     LoadConfig.loadConfigFolder();
    _scenesManager.addMultipleScenes(LoadConfig.loadConfigFolder());
    auto &actualScene = _scenesManager.getSceneActual();
    _observer.subscribe(actualScene.getFileName());
    actualScene.calculateImage();
}

void Raytracer::Core::run()
{
    while (!_eventManager.isEventTriggered("Quit")) {
        _eventManager.clear();
        _eventManager.update();
        _scenesManager.update(_eventManager);
        _observer.checkEditedFiles();
        _displayModule.update(_scenesManager.getSceneActual().getImage());
    }
}
