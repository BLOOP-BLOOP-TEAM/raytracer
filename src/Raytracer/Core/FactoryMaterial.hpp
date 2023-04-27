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

    void addCreator(const std::string &name, std::function<void()> func);


protected:
private:
    std::map<std::string, std::function<void()>> _map;
};
