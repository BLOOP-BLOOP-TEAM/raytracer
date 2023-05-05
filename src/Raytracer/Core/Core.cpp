/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Core
*/

#include "Core.hpp"

static const std::string FOLDER = "./plugins";

Raytracer::Core::Core()
        : _loadPlugin(std::make_unique<PluginLoader>()),
          _scenesManager(std::make_unique<ScenesManager>()),
          _displayModule(std::make_unique<DisplayModule>(1920, 1080, "Raytracer")),
          _eventManager(std::make_unique<EventManager>(_displayModule->getWindow())),
          _observer(std::make_unique<Observer>())
{
<<<<<<< HEAD
    LoadPlugin loadPlugin;
    LoadConfig LoadConfig;
    
    loadPlugin.loadPluginsFromDirectory(FOLDER);
    LoadConfig.loadConfigFolder();
    std::cout << "Load config" << std::endl;
    auto &actualScene = _scenesManager.getSceneActual();
    _observer.subscribe(actualScene.getFileName());
=======
    _loadPlugin->loadPluginsFromDirectory(FOLDER);
    ConfigLoader LoadConfig;

    _scenesManager->addMultipleScenes(*LoadConfig.loadConfigFolder());
    auto &actualScene = _scenesManager->getSceneActual();
    _observer->subscribe(actualScene.getFileName());
>>>>>>> RAYT-37-tester-fix-linitialisation
    actualScene.calculateImage();
}

Raytracer::Core::~Core()
{
    _scenesManager.reset();
}

void Raytracer::Core::run()
{
    while (!_eventManager->isEventTriggered("Quit")) {
        _eventManager->clear();
        _eventManager->update();
        _scenesManager->update(*_eventManager);
        _observer->checkEditedFiles();
        _displayModule->update(_scenesManager->getSceneActual().getImage());
    }
}
