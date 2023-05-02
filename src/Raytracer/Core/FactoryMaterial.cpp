/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FactoryMaterial
*/

#include <iostream>
#include "FactoryMaterial.hpp"

Raytracer::FactoryMaterial &Raytracer::FactoryMaterial::getInstance()
{
    static Raytracer::FactoryMaterial instance;
    return (instance);
}

Raytracer::IMaterial &Raytracer::FactoryMaterial::createMaterial(const std::string &name, libconfig::Setting &data)
{
    Raytracer::IMaterial *result = _materials[name].first(data);

    if (result == nullptr) {
        //throw
    }
    return (*result);
}

void Raytracer::FactoryMaterial::destroyMaterial(const Raytracer::IMaterial &material)
{
    Raytracer::AMaterial *mat = static_cast<Raytracer::AMaterial *>(&material);

    _materials[mat->getType()].second(&material);
}

void Raytracer::FactoryMaterial::addCreator(
    const std::string &name,
    std::function<Raytracer::IMaterial *(const libconfig::Setting &)> funCreate,
    std::function<void(Raytracer::IMaterial *material)> funcDestroy)
{
    auto funcPair = std::make_pair(funCreate, funcDestroy);

    _materials.insert({name, funcPair});
}

const std::map<std::string, std::pair<std::function<Raytracer::IMaterial *(const libconfig::Setting &)>, std::function<void(Raytracer::IMaterial *material)>>>& Raytracer::FactoryMaterial::getMaterials() const
{
    return (_materials);
}
