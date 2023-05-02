/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FactoryMaterial
*/

#include <iostream>
#include "FactoryMaterial.hpp"


Raytracer::IMaterial &Raytracer::FactoryMaterial::createMaterial(const std::string &name, libconfig::Setting &data)
{
    return (*_materials[name].first(data));
    //throw std::runtime_error("Runtime error");
}

void Raytracer::FactoryMaterial::destroyMaterial(Raytracer::IMaterial &material)
{
    Raytracer::AMaterial *mat = static_cast<Raytracer::AMaterial *>(&material);

    if (mat == nullptr) {
        return;
    }
    _materials[mat->getType()].second(&material);
}

void Raytracer::FactoryMaterial::addCreator(
    const std::string &name,
    std::function<Raytracer::IMaterial *(const libconfig::Setting &)> funCreate,
    std::function<void(Raytracer::IMaterial *material)> funcDestroy)
{
    auto funcPair = std::make_pair(funCreate, funcDestroy);

    this->_materials.insert({name, funcPair});
}
