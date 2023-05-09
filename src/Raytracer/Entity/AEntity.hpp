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
        AEntity(Raytracer::CompType type, const Component::Vector3f &position, const Component::Vector3f &rotation);

        ~AEntity() override = default;

        void translate(const Component::Vector3f &newPos) final;

        void rotate(const Component::Vector3f &newRot) final;

        void scale(const Component::Vector3f &newScale) final;

        [[nodiscard]] Component::Vector3f getPosition() const final;

        [[nodiscard]] Raytracer::CompType getType() const final;

        [[nodiscard]] Component::Vector3f getRotation() const final;

    protected:
        Component::Vector3f _position;
        Component::Vector3f _rotation;
        Component::Vector3f _scale;
    private:
        Raytracer::CompType _type;
    };
};
