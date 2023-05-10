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

        void addMultipleScenes(std::unique_ptr<std::vector<std::unique_ptr<Scene>>> scenes);

        void replaceScene(std::unique_ptr<Scene> newScene, const std::string &path);

        void removeScene(const std::string &path);

        [[nodiscard]] Scene &getSceneActual() const;

        void setSceneActual(int scene);

        void update(Raytracer::EventManager &eventManager);

        [[nodiscard]] ACam &getCam() const;

        void moveCamera(std::string key, bool isCtrlPressed);

        [[nodiscard]] bool isCtrlActive() const;

    protected:
    private:
        std::vector<std::unique_ptr<Scene>> _scenes;
        int _sceneActual;
        bool _isCtrlActive;
    };
};
