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
#include <variant>
#include <functional>
#include <libconfig.h++>
#include "IEntity.hpp"

namespace Raytracer {
    class FactoryEntity {
    public:
        FactoryEntity() = default;
        ~FactoryEntity() = default;
        FactoryEntity(const FactoryEntity&) = delete;
        FactoryEntity& operator=(const FactoryEntity&) = delete;
        static FactoryEntity& getInstance();
        IEntity *createEntity(const std::string &name, const std::map<std::string, std::variant<double, int, std::string, bool>> &setting);
        void destroyEntity(IEntity *entity);
        void addCreator(const std::string &name, const std::function<Raytracer::IEntity *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>& funcCreate, const std::function<void(Raytracer::IEntity *entity)>& funcDestroy);

    private:

        std::map<std::string, std::pair<std::function<Raytracer::IEntity *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>, std::function<void(Raytracer::IEntity *entity)>>> _entities;
    };
};
