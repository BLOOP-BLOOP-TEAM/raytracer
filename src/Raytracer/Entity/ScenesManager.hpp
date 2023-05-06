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
    /**
     * @brief The ScenesManager class
     *
     * This is the class that will handle all the scenes loaded.
     */
    class ScenesManager {
    public:
        /**
         * @brief Constructor of ScenesManager
         *
         * Set the actual scene to 0.
         */
        ScenesManager();
        ~ScenesManager() = default;

        /**
         * @brief Function that add scene
         *
         * This function take a scene and add it to _scenes variable
         *
         * @param scene a unique ptr on a Scene object
         */
        void addScene(std::unique_ptr<Scene> scene);

        void addMultipleScenes(std::vector<std::unique_ptr<Scene>> &scenes);

        /**
         * @brief Function that get the actual scene
         *
         * This function is a getter that return the actual scene selected.
         */
        [[nodiscard]] Scene &getSceneActual() const;

        /**
         * @brief Function that set the actual scene
         *
         * This function set the _sceneActual variable to a number that is given
         * On error this function will throw a RaytracerException.
         *
         * @param scene an int that will be the index of the actual scene.
         */
        void setSceneActual(int scene);

        /**
         * @brief Function that update
         *
         * This function will update the actual scene that is selected
         *
         * @param eventManager an EventManager object that handle all the events
         */
        void update(Raytracer::EventManager &eventManager);

    protected:
    private:
        std::vector<std::unique_ptr<Scene>> _scenes;
        int _sceneActual;
    };
};
