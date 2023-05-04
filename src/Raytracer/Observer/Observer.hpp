/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Observer
*/

#pragma once
#include "vector"
#include "string"
#include "iostream" // à enlever
#include <filesystem>
#include <chrono>
#include <algorithm>

namespace Raytracer {
    class Observer {
        public:
            Observer(std::vector<std::string> allScenes = {});

            ~Observer() = default;

            void checkEditedFiles();

            void notify(const std::string &path);

            void subscribe(const std::string &path);

            void unsubscribe(const std::string &path);

            std::time_t getTimeStamp(const std::string &path);

        private:
            std::vector<std::string> _allSubScenes;
            std::vector<std::time_t> _lastUpdates;
    };
};
