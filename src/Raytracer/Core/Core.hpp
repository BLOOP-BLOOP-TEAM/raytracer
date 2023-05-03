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
#include "LoadPlugin.hpp"
#include "Observer.hpp"

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
        Observer _observer;
        bool _isRunning;
    };
};
