/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Observer
*/

#pragma once
#include <filesystem>
#include <cstring>
#include <chrono>
#include <algorithm>
#include <vector>
#include <string>
#include "ScenesManager.hpp"

namespace Raytracer {
    class Observer {
        public:
            Observer(ScenesManager &sceneManager);

            ~Observer() = default;

            void checkEditedFiles();

            void notify(const std::string &path);

            void subscribe(const std::string &path);

            void checkNewFiles();

            void checkUnsubFileDeleted();

            bool isFileExist(const std::string &path);

            void unsubscribe(const std::string &path);

            std::time_t getTimeStamp(const std::string &path, bool isSub);

        private:
            void replaceScene(const std::string &path);

            std::vector<std::string> _allSubScenes = {};
            std::vector<std::time_t> _lastUpdates;
            ScenesManager &_sceneManager;
    };
};
