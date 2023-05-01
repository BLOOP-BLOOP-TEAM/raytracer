/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AEntity
*/

#pragma once

#include <string>
#include "CompType.hpp"
#include "IEntity.hpp"

namespace Raytracer {
    class AEntity : public IEntity {
    public:
        AEntity(Raytracer::CompType type, const Component::Vector3f &position);

        ~AEntity() override = default;

        void translate(const Component::Vector3f &newPos) final;

        void rotate(const Component::Vector3f &newRot) final;

        void scale(const Component::Vector3f &newScale) final;

        [[nodiscard]] Component::Vector3f getPosition() const final;

        Raytracer::CompType getType() const;

    protected:
    private:
        Raytracer::CompType _type;
        Component::Vector3f _position;
        Component::Vector3f _rotation;
    };
};
