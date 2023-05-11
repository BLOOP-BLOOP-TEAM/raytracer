/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** FactorySkybox
*/

#include "RaytracerException.hpp"
#include "FactorySkybox.hpp"

Raytracer::FactorySkybox &Raytracer::FactorySkybox::getInstance()
{
    static Raytracer::FactorySkybox instance;
    return instance;
}

Raytracer::ISkybox *Raytracer::FactorySkybox::createSkybox(const std::string &name, const std::map<std::string, std::variant<double, int, std::string, bool>> &properties)
{
    if (_materials.find(name) == _materials.end())
        throw Raytracer::RaytracerException("Skybox " + name + " not found");
    return _materials[name].first(properties);
}

void Raytracer::FactorySkybox::destroySkybox(Raytracer::ISkybox *skybox)
{
    Raytracer::ASkybox *sky = static_cast<Raytracer::ASkybox *>(skybox);

    _materials[sky->getType()].second(skybox);
}

void Raytracer::FactorySkybox::addCreator(
    const std::string &name,
    const std::function<Raytracer::ISkybox *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>& funCreate,
    const std::function<void(Raytracer::ISkybox *skybox)>& funcDestroy)
{
    auto funcPair = std::make_pair(funCreate, funcDestroy);

    _materials.insert({name, funcPair});
}
