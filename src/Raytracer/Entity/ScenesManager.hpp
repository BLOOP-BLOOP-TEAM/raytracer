/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ScenesManager
*/

#pragma once

#include <vector>
#include <functional>
#include <string>
#include "Scenes.hpp"

namespace Raytracer {
    class ScenesManager {
    public:
        ScenesManager();
        ~ScenesManager();

        void addScene(Scenes &scene);

        int getSceneCount() const;

        Scenes &getScene(int index) const;

        Scenes &getScene(std::string name) const;

    protected:
    private:
        std::vector<std::reference_wrapper<Scenes>> _scenes;
    };
};