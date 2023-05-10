/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FactorySkybox
*/

#pragma once

#include <map>
#include <functional>
#include <string>
#include <libconfig.h++>
#include "ASkybox.hpp"


namespace Raytracer {
    class FactorySkybox {
    public:
        FactorySkybox() = default;
        ~FactorySkybox() = default;
        FactorySkybox(const FactorySkybox&) = delete;
        FactorySkybox& operator=(const FactorySkybox&) = delete;
        static FactorySkybox& getInstance();
        Raytracer::ISkybox *createSkybox(const std::string &name, const std::map<std::string, std::variant<double, int, std::string, bool>> &);
        void destroySkybox(Raytracer::ISkybox *skybox);
        void addCreator(const std::string &name, std::function<Raytracer::ISkybox *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)> funcCreate, std::function<void(Raytracer::ISkybox *skybox)> funcDestroy);

    private:
        std::map<std::string, std::pair<std::function<Raytracer::ISkybox *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>, std::function<void(Raytracer::ISkybox *skybox)>>> _materials;
    };
}
