/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Observer
*/

#pragma once
#include <filesystem>
#include <chrono>
#include <algorithm>
#include <vector>
#include <string>
#include "ScenesManager.hpp"

namespace Raytracer {
    /**
     * @brief The Observer class
     * 
     * The observer class is a class that, at runtime, will check
     * if a config file has been updated.
     */
    class Observer {
        public:
            Observer(ScenesManager &sceneManager);

            ~Observer() = default;

            /**
             * @brief Function that check files
             * 
             * This function will check if a file has been updated or not
             */
            void checkEditedFiles();

            /**
             * @brief Notify if there is any change
             * 
             * This function will notify when a config file has changed and load 
             * the new config file
             * 
             * @param path the path to the file
             */
            void notify(const std::string &path);

            /**
             * @brief Function that subscribe scene.
             * 
             * Subscribe a scene and add it to the allSubScenes variable
             * The config file of the scene will be checked by the observer.
             * 
             * @param path string that represent the scene to subscribe.
             */
            void subscribe(const std::string &path);

            /**
             * @brief Function that unsubscribe a scene
             * 
             * The scene that will be given to this function will no longer be checked
             * by the observer.
             * 
             * @param path string that represent the scene to unsubscribe
             */
            void unsubscribe(const std::string &path);

            /**
             * @brief Function that get the time stamp of a file
             * 
             * This function will check if the file exists
             */
            std::time_t getTimeStamp(const std::string &path);

        private:
            void replaceScene(const std::string &path);

            std::vector<std::string> _allSubScenes = {};
            std::vector<std::time_t> _lastUpdates;
            ScenesManager &_sceneManager;
    };
};
