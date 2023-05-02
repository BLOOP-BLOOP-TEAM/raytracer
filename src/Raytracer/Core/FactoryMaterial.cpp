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
    for (auto it = this->_materials.begin(); it != this->_materials.end(); it++) {
        if (name == it->first) {
            return (*it->second.first(data));
        }
    }
    throw std::runtime_error("Marche pas");
}

void Raytracer::FactoryMaterial::destroyMaterial(Raytracer::IMaterial &material)
{
    Raytracer::AMaterial *mat = dynamic_cast<Raytracer::AMaterial *>(&material);

    if (mat == nullptr) {
        return;
    }
    for (auto it = this->_materials.begin(); it != this->_materials.end(); it++) {
        if (it->first == mat->getType()) {
            it->second.second(&material);
        }
    }
}

void Raytracer::FactoryMaterial::addCreator(
    const std::string &name,
    std::function<Raytracer::IMaterial *(const libconfig::Setting &)> funCreate,
    std::function<void(Raytracer::IMaterial *material)> funcDestroy)
{
    auto funcPair = std::make_pair(funCreate, funcDestroy);

    this->_materials.insert({name, funcPair});
}
