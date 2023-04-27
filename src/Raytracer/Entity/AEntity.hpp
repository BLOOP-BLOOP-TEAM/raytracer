/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AEntity
*/

#pragma once

#include <string>
#include "IEntity.hpp"

namespace Raytracer {
    class AEntity : public IEntity {
    public:
        AEntity(const std::string &type, const Component::Vector3f &position);

        ~AEntity() = default;

    protected:
    private:
        const std::string _type;
        Component::Vector3f _position;
    };
};
