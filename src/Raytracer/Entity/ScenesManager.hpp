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
    class ScenesManager {
    public:
        ScenesManager();
        ~ScenesManager();

        void addScene(Scene &scene);

        Scene &getSceneActual() const;

    protected:
    private:
        std::vector<std::shared_ptr<Scene>> _scenes;
    };
};
