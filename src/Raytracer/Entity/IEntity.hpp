/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IEntity
*/

#pragma once

#include "Vector3f.hpp"
#include "CompType.hpp"

namespace Raytracer {
    class IEntity {
        public:

            virtual ~IEntity() = default;
            virtual void translate(const Component::Vector3f &newPos) = 0;
            virtual void rotate(const Component::Vector3f &newRot) = 0;
            virtual void scale(const Component::Vector3f &newScale) = 0;
            [[nodiscard]] virtual Component::Vector3f getPosition() const = 0;
            [[nodiscard]] virtual Raytracer::CompType getType() const = 0;
        protected:
        private:

    };
};
