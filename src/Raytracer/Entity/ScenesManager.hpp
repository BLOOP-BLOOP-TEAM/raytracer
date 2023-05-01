/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ScenesManager
*/

#pragma once

#include <vector>
#include <string>
#include <memory>
#include "Scene.hpp"
#include "EventManager.hpp"

namespace Raytracer {
    class ScenesManager {
    public:
        ScenesManager();
        ~ScenesManager() = default;

        void addScene(std::unique_ptr<Scene> scene);

        [[nodiscard]] Scene &getSceneActual() const;

        void setSceneActual(int scene);

        void update(Raytracer::EventManager &eventManager);

    protected:
    private:
        std::vector<std::unique_ptr<Scene>> _scenes;
        int _sceneActual;
    };
};
