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

namespace Raytracer {
    class Observer;
}

namespace Raytracer {
    class ScenesManager {
    public:
        ScenesManager();
        ~ScenesManager() = default;

        void addScene(std::unique_ptr<Scene> scene);

        void addMultipleScenes(std::unique_ptr<std::vector<std::unique_ptr<Scene>>> scenes);

        void replaceScene(std::unique_ptr<Scene> newScene, const std::string &path);

        void removeScene(const std::string &path);

        [[nodiscard]] Scene &getSceneActual() const;

        [[nodiscard]] int getNumberScenes() const;

        [[nodiscard]] int getIndexActualScene() const;

        [[nodiscard]] const std::vector<std::unique_ptr<Scene>> &getScenes() const;

        void setSceneActual(int scene);

        void update(Raytracer::EventManager &eventManager, Raytracer::Observer &observer);

        [[nodiscard]] ACam &getCam() const;

        void moveCamera(std::string key, bool isCtrlPressed) const;

        [[nodiscard]] bool isCtrlActive() const;

    protected:
    private:
        std::vector<std::unique_ptr<Scene>> _scenes;
        int _sceneActual;
        bool _isCtrlActive;
    };
};
