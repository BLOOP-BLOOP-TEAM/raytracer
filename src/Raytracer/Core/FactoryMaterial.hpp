/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FactoryMaterial
*/

#pragma once

#include <map>
#include <functional>
#include <string>
#include <libconfig.h++>
#include "AMaterial.hpp"

namespace Raytracer {
    class FactoryMaterial {
    public:
        FactoryMaterial() = default;
        ~FactoryMaterial() = default;
        FactoryMaterial(const FactoryMaterial&) = delete;
        FactoryMaterial& operator=(const FactoryMaterial&) = delete;
        static FactoryMaterial& getInstance();
        Raytracer::IMaterial *createMaterial(const std::string &name, const std::map<std::string, std::variant<double, int, std::string, bool>> &);
        void destroyMaterial(Raytracer::IMaterial *material);
        void addCreator(const std::string &name, const std::function<Raytracer::IMaterial *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>& funcCreate, const std::function<void(Raytracer::IMaterial *material)>& funcDestroy);

    private:
        std::map<std::string, std::pair<std::function<Raytracer::IMaterial *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>, std::function<void(Raytracer::IMaterial *material)>>> _materials;
    };
}
