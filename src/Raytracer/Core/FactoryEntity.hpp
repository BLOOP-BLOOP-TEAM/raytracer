/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Factory
*/

#pragma once

#include <map>
#include <string>
#include <vector>
#include <functional>
#include <libconfig.h++>
#include "IEntity.hpp"

namespace Raytracer {

    class FactoryEntity {
    public:
        FactoryEntity() = default;

        ~FactoryEntity() = default;

        IEntity *createEntity(const std::string &name, const libconfig::Setting &setting);

        void destroyEntity(IEntity *entity);

        void addCreator(const std::string &name, std::function<Raytracer::IEntity *(const libconfig::Setting &)> funcCreate, std::function<void(Raytracer::IEntity *entity)> funcDestroy);


    protected:
    private:
        std::map<std::string, std::pair<std::function<Raytracer::IEntity *(const libconfig::Setting &)>, std::function<void(Raytracer::IEntity *entity)>>> _entities;
    };
};
