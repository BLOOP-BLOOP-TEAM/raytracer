/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Factory
*/

#include "FactoryEntity.hpp"

Raytracer::IEntity *Raytracer::FactoryEntity::createEntity(const std::string &name, const libconfig::Setting &setting)
{
    return (_entities[name].first(setting));
}

void Raytracer::FactoryEntity::destroyEntity(IEntity *entity)
{
    if (entity != nullptr) {
        delete (entity);
    }
}

void Raytracer::FactoryEntity::addCreator(
    const std::string &name,
    std::function<Raytracer::IEntity *(const libconfig::Setting &)> funcCreate,
    std::function<void(Raytracer::IEntity *entity)> funcDestroy)
{
    auto funcPair = std::make_pair(funcCreate, funcDestroy);

    _entities.insert({name, funcPair});
}
