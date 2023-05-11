/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FactoryMaterial
*/

#include "RaytracerException.hpp"
#include "FactoryMaterial.hpp"

Raytracer::FactoryMaterial &Raytracer::FactoryMaterial::getInstance()
{
    static Raytracer::FactoryMaterial instance;
    return (instance);
}

Raytracer::IMaterial *Raytracer::FactoryMaterial::createMaterial(const std::string &name, const std::map<std::string, std::variant<double, int, std::string, bool>> &data)
{
    Raytracer::IMaterial *result = _materials[name].first(data);

    if (result == nullptr) {
        throw Raytracer::RaytracerException("Material " + name + " not found");
    }
    return (result);
}

void Raytracer::FactoryMaterial::destroyMaterial(Raytracer::IMaterial *material)
{
    Raytracer::AMaterial *mat = static_cast<Raytracer::AMaterial *>(material);

    _materials[mat->getType()].second(material);
}

void Raytracer::FactoryMaterial::addCreator(
    const std::string &name,
    const std::function<Raytracer::IMaterial *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>& funCreate,
    const std::function<void(Raytracer::IMaterial *material)>& funcDestroy)
{
    auto funcPair = std::make_pair(funCreate, funcDestroy);

    _materials.insert({name, funcPair});
}
