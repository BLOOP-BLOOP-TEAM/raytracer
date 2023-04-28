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
#include "IMaterial.hpp"


class FactoryMaterial {
public:
    FactoryMaterial();

    ~FactoryMaterial() = default;

    //IMaterial &createEntity(const std::string &name, LibConfig);

    void addCreator(const std::string &name, std::function<void()> funcCreate, std::function<void()> funcDestroy);


protected:
private:
    std::map<std::string, std::pair<std::function<void()>, std::function<void()>>> _materials;
};
