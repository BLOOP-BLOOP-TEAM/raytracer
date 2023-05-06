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
    /**
    * @brief The AEntity class
    * 
    * The AEntity class defines the common methods that all Entity objects will have.
    * It extends the IEntity class.
    */
    class AEntity : public IEntity {
        public:
            /**
             * @brief Constructor for AEntity
             * 
             * @param type The type of the entity as a CompType enum
             * @param position The position of the entity as a Vector3f
             */
            AEntity(Raytracer::CompType type, const Component::Vector3f &position);

            ~AEntity() override = default;

            /**
             * @brief Function that translates the entity to a new position
             * 
             * @param newPos The new position of the entity as a Vector3f
             */
            void translate(const Component::Vector3f &newPos) final;

            /**
             * @brief Function that rotates the entity to a new rotation
             * 
             * @param newRot The new rotation of the entity as a Vector3f
             */
            void rotate(const Component::Vector3f &newRot) final;

            /**
             * @brief Function that scales the entity to a new scale
             * 
             * @param newScale The new scale of the entity as a Vector3f
             */
            void scale(const Component::Vector3f &newScale) final;

            /**
             * @brief Function that gets the position of the entity
             */
            [[nodiscard]] Component::Vector3f getPosition() const final;

            /**
             * @brief Function that gets the type of the entity
             */
            [[nodiscard]] Raytracer::CompType getType() const final;
        protected:
            Component::Vector3f _position;
            Component::Vector3f _rotation;
            Component::Vector3f _scale;
        private:
            Raytracer::CompType _type;
    };
};
