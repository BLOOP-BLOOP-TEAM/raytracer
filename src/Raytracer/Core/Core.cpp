/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Core
*/

#include "Core.hpp"

Raytracer::Core::Core() : _isRunning(true), _scenesManager(), _displayModule(1920, 1080, "Raytracer"), _eventManager(_displayModule.getWindow())
{
    // load library
    // load config
    // build factory
    // build scenes
    // Calculate
    // create ppm
    // create displayModule
}

void Raytracer::Core::run()
{
    while (_isRunning) {
        _eventManager.update();
        // Observe
        _scenesManager.update(_eventManager);
        _displayModule.update(_scenesManager.getSceneActual().getImage());
        _eventManager.clear();
    }
}
