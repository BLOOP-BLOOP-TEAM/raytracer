/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder
*/

#pragma once

#include "APrimitive.hpp"
#include "Vector3f.hpp"

namespace Plugin {
    /**
     * @brief The Cylinder class represents a cylinder primitive in a 3D scene.
     */
    class Cylinder : public Raytracer::APrimitive {
        public:
            /**
             * @brief Constructor for Cylinder class.
             * 
             * @param position The position of the cylinder.
             * @param radius The radius of the cylinder.
             * @param height The height of the cylinder.
             * @param basePoint The base point of the cylinder.
             * @param topPoint The top point of the cylinder.
             */
            Cylinder(const Component::Vector3f &position, double radius, double height,
                    Component::Vector3f &basePoint, Component::Vector3f &topPoint);

            ~Cylinder();

            /**
             * @brief Computes the intersection point between the cylinder and a given ray.
             * 
             * @param ray The ray to intersect with the cylinder.
             */
            [[nodiscard]] double intersect(const Raytracer::Ray &ray) const override;

            /**
             * @brief Gets the normal vector of the cylinder at a given point.
             * 
             * @param hitPoint The point at which to compute the normal.
             */
            [[nodiscard]] Component::Vector3f getNormal(const Component::Vector3f &hitPoint) const override;

        protected:
        private:
            /**
             * @brief Calculates the axis of the cylinder.
             * 
             * @param basePoint The base point of the cylinder.
             * @param topPoint The top point of the cylinder.
             */
            Component::Vector3f calculateCylinderAxis(const Component::Vector3f &basePoint, const Component::Vector3f &topPoint);

            double _radius;
            double _height;
            Component::Vector3f _axis;
    };
}