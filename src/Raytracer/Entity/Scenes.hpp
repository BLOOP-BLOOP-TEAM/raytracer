/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Scenes
*/

#pragma once

#include <vector>
#include <string>
#include <memory>
#include "IEntity.hpp"

namespace Raytracer {
    class Scenes {
    public:
        Scenes();

        ~Scenes();

        void addEntity(IEntity &entity);

        IEntity &getEntity(int index) const;

        IEntity &getEntity(std::string name) const;

    protected:
    private:
        std::vector<std::unique_ptr<IEntity>> _entities;
    };
};
