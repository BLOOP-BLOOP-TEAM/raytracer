/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane
*/

#pragma once

#include "APrimitive.hpp"
#include "Ray.hpp"
#include "Vector3f.hpp"

namespace Plugin {
    /**
     * @brief The Plane class represents a plane primitive in a 3D scene.
     */
    class Plane : public Raytracer::APrimitive {
        public:
            /**
             * @brief Constructor for Plane class.
             * 
             * @param position The position of the plane.
             * @param normal The normal vector of the plane.
             */
            Plane(const Component::Vector3f &position, const Component::Vector3f &normal);

            virtual ~Plane() = default;

            /**
             * @brief Computes the intersection point between the plane and a given ray.
             * 
             * @param ray The ray to intersect with the plane.
             */
            float intersect(const Raytracer::Ray &ray) const override;

            /**
             * @brief Gets the normal vector of the plane at a given point.
             * 
             * @param hitPoint The point at which to compute the normal.
             */
            Component::Vector3f getNormal(const Component::Vector3f &hitPoint) const override;

            /**
             * @brief Gets the color of the plane at a given point.
             * 
             * @param hitPoint The point at which to compute the color.
             */
            Component::Color getColor(const Component::Vector3f &hitPoint) const override;

    private:
        Component::Vector3f _normal;
    };
}
