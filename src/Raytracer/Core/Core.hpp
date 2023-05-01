/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Core
*/

#pragma once

#include "DisplayModule.hpp"
#include "EventManager.hpp"
#include "ScenesManager.hpp"

namespace Raytracer {
    class Core {
    public:
        Core();

        ~Core() = default;
        void run();

    protected:
    private:
        ScenesManager _scenesManager;
        DisplayModule _displayModule;
        EventManager _eventManager;
        bool _isRunning;
    };
};
