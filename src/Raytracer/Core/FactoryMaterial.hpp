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
#include "IMaterial.hpp"


class FactoryMaterial {
public:
    FactoryMaterial();

    ~FactoryMaterial() = default;

    Raytracer::IMaterial &createMaterial(const std::string &name, libconfig::Setting &);

    void destroyMaterial(Raytracer::IMaterial &material);

    void addCreator(const std::string &name, std::function<Raytracer::IMaterial *(const libconfig::Setting &)> funcCreate, std::function<void(Raytracer::IMaterial *material)> funcDestroy);


protected:
private:
    std::map<std::string, std::pair<std::function<Raytracer::IMaterial *(const libconfig::Setting &)>, std::function<void(Raytracer::IMaterial *material)>>> _materials;
};
