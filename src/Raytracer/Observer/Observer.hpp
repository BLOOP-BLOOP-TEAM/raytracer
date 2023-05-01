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

class Observer {
    public:
        Observer(std::vector<std::string> allScenes = {});

        ~Observer();

        void checkEditedFiles();

        void notify(std::string path);

        void subscribe(std::string path);

        std::time_t getTimeStamp(std::string path);

    private:
        std::vector<std::string> _allSubScenes;
        std::vector<std::time_t> _lastUpdates;
};
