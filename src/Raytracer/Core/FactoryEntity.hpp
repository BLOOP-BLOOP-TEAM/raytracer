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
#include "IEntity.hpp"

namespace Raytracer {

    class FactoryEntity {
    public:
        FactoryEntity();

        ~FactoryEntity() = default;

        //IEntity &createEntity(const std::string &name, LibConfig);

        void addCreator(const std::string &name, std::function<void()> func);


    protected:
    private:
        std::map<std::string, std::function<void()>> _map;
    };
};
