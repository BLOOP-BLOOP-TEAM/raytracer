/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EntityManager
*/

#pragma once

#include <vector>
#include <functional>
#include <string>
#include "IEntity.hpp"

namespace Raytracer {
    class EntityManager {
    public:
        EntityManager();

        ~EntityManager();

        void addEntity(IEntity &entity);

        int getEntityCount() const;

        IEntity &getEntity(int index) const;

        IEntity &getEntity(std::string name) const;

    protected:
    private:
        std::vector<std::reference_wrapper<IEntity>> _entities;
    };
};
