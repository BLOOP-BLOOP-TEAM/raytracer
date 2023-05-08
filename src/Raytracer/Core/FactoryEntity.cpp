/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Factory
*/

#include <iostream>
#include <stdexcept>
#include "FactoryEntity.hpp"
#include "AEntity.hpp"
#include "ACam.hpp"
#include "ALight.hpp"
#include "APrimitive.hpp"
#include "RaytracerException.hpp"

Raytracer::IEntity* Raytracer::FactoryEntity::createEntity(const std::string &name, const std::map<std::string, std::variant<double, int, std::string, bool>> &setting)
{
    Raytracer::IEntity *result = _entities[name].first(setting);

    if (result == nullptr) {
        throw Raytracer::RaytracerException("Error: Entity not found");
    }
    return (result);
}

void Raytracer::FactoryEntity::destroyEntity(Raytracer::IEntity *entity)
{
    AEntity *ent = static_cast<AEntity *>(entity);

    auto test = entity->getType();

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

void Raytracer::FactoryEntity::addCreator(const std::string &name, const std::function<Raytracer::IEntity *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>& funcCreate, const std::function<void(Raytracer::IEntity *entity)>& funcDestroy)
{
    _entities[name] = std::make_pair(funcCreate, funcDestroy);
}

Raytracer::FactoryEntity &Raytracer::FactoryEntity::getInstance()
{
    static Raytracer::FactoryEntity instance;
    return instance;
}
