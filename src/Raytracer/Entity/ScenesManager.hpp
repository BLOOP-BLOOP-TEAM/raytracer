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

        int getSceneCount() const;

        Scenes &getScene(int index) const;

        Scenes &getScene(const std::string &name) const;

    protected:
    private:
        std::vector<std::unique_ptr<Scenes>> _scenes;
    };
};
