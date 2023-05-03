/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Core
*/

#include "Core.hpp"

static const std::string FOLDER_NAME = "./src/Plugins";

Raytracer::Core::Core() : _isRunning(true), _scenesManager(), _displayModule(1920, 1080, "Raytracer"), _eventManager(_displayModule.getWindow()), _observer()
{
    LoadPlugin loadPlugin;
    // load config

    loadPlugin.loadPluginsFromDirectory(FOLDER_NAME);
    auto &actualScene = _scenesManager.getSceneActual();
    _observer.subscribe(actualScene.getFileName());
    actualScene.calculateImage();
}

void Raytracer::Core::run()
{
    while (_isRunning) {
        _eventManager.update();
        _scenesManager.update(_eventManager);
        _observer.checkEditedFiles();
        _displayModule.update(_scenesManager.getSceneActual().getImage());
        _eventManager.clear();
    }
}
