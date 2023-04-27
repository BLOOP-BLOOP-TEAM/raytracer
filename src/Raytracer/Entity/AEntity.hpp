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

        void translate(const Component::Vector3f &newPos) final;

        void rotate(const Component::Vector3f &newRot) final;

        void scale(const Component::Vector3f &newScale) final;

        Component::Vector3f getPosition() const final;

    protected:
    private:
        const std::string _type;
        Component::Vector3f _position;
        Component::Vector3f _rotation;
    };
};
