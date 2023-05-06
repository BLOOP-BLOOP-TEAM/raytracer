/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Factory
*/

#include <stdexcept>
#include "FactoryEntity.hpp"
#include "AEntity.hpp"
#include "ACam.hpp"
#include "ALight.hpp"
#include "APrimitive.hpp"
#include "RaytracerException.hpp"
Raytracer::IEntity* Raytracer::FactoryEntity::createEntity(const std::string &name, const libconfig::Setting &setting)
{
    Raytracer::IEntity *result = nullptr;

    if (_entities.find(name) == _entities.end()) {
        throw Raytracer::RaytracerException("Error: Entity not found");
    }
    result = _entities[name].first(setting);

    if (result == nullptr) {
        throw Raytracer::RaytracerException("Error: Entity not found");
    }
    return (result);
}

void Raytracer::FactoryEntity::destroyEntity(Raytracer::IEntity *entity)
{
    AEntity *ent = static_cast<AEntity *>(entity);

    if (ent->getType() == Raytracer::CompType::CAM) {
        ACam *cam = static_cast<ACam *>(ent);
        _entities[cam->getTypeCam()].second(entity);
    } else if (ent->getType() == Raytracer::CompType::LIGHT) {
        ALight *light = static_cast<ALight *>(ent);
        _entities[light->getTypeLight()].second(entity);
    } else if (ent->getType() == Raytracer::CompType::PRIMITIVE) {
        APrimitive *primitive = static_cast<APrimitive *>(ent);
        _entities[primitive->getTypePrimitive()].second(entity);
    } else {
        //throw
    }
}

void Raytracer::FactoryEntity::addCreator(const std::string &name, const std::function<Raytracer::IEntity *(const libconfig::Setting &)>& funcCreate, const std::function<void(Raytracer::IEntity *entity)>& funcDestroy)
{
    _entities[name] = std::make_pair(funcCreate, funcDestroy);
}

const std::map<std::string, std::pair<std::function<Raytracer::IEntity *(const libconfig::Setting &)>, std::function<void(Raytracer::IEntity *entity)>>>& Raytracer::FactoryEntity::getEntities() const
{
    return _entities;
}

Raytracer::FactoryEntity &Raytracer::FactoryEntity::getInstance()
{
    static Raytracer::FactoryEntity instance;
    return instance;
}
