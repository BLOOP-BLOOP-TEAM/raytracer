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
#include "Scenes.hpp"

namespace Raytracer {
    class ScenesManager {
    public:
        ScenesManager();
        ~ScenesManager();

        void addScene(Scenes &scene);

        Scenes &getSceneActual() const;

    protected:
    private:
        std::vector<std::shared_ptr<Scenes>> _scenes;
    };
};
