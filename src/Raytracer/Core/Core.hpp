/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Core
*/

#pragma once

#include <memory>
#include "DisplayModule.hpp"
#include "EventManager.hpp"
#include "ScenesManager.hpp"
#include "PluginLoader.hpp"
#include "Observer.hpp"
#include "ConfigLoader.hpp"

namespace Raytracer {
    /**
     * @brief The Core class is the main class of the Raytracer program.
     */
    class Core {
        public:
            Core();

            ~Core();

            /**
             * @brief Runs the Raytracer program.
             */
            void run();

        protected:
        private:
            std::unique_ptr<PluginLoader> _loadPlugin;
            std::unique_ptr<ScenesManager> _scenesManager;
            std::unique_ptr<DisplayModule> _displayModule;
            std::unique_ptr<EventManager> _eventManager;
            std::unique_ptr<Observer> _observer;
    };
};
