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
    /**
     * @brief The IEntity class
     * 
     * The IEntity class defines the common methods of Entity objects.
     */
    class IEntity {
        public:
            virtual ~IEntity() = default;
    
            /**
             * @brief Translates the entity to a new position
             * 
             * @param newPos The new position of the entity as a Component::Vector3f object
             */
            virtual void translate(const Component::Vector3f &newPos) = 0;
    
            /**
             * @brief Rotates the entity to a new rotation
             * 
             * @param newRot The new rotation of the entity as a Component::Vector3f object
             */
            virtual void rotate(const Component::Vector3f &newRot) = 0;
    
            /**
             * @brief Scales the entity to a new scale
             * 
             * @param newScale The new scale of the entity as a Component::Vector3f object
             */
            virtual void scale(const Component::Vector3f &newScale) = 0;
    
            /**
             * @brief Gets the position of the entity
             */
            [[nodiscard]] virtual Component::Vector3f getPosition() const = 0;
    
            /**
             * @brief Gets the type of the entity
             */
            [[nodiscard]] virtual Raytracer::CompType getType() const = 0;

            /**
             * @brief Gets the rotation of the entity
             */
            [[nodiscard]] virtual Component::Vector3f getRotation() const = 0;
        protected:
        private:

    };
};
