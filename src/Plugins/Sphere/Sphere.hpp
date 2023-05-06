/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere
*/

#pragma once

#include "APrimitive.hpp"
#include "Ray.hpp"
#include "Vector3f.hpp"

namespace Plugin {
    /**
     * @brief The Sphere class represents a sphere primitive in a 3D scene.
     */
    class Sphere : public Raytracer::APrimitive {
        public:
            /**
             * @brief Constructor for Sphere class.
             * 
             * @param position The center position of the sphere.
             * @param radius The radius of the sphere.
             */
            Sphere(const Component::Vector3f &position, double radius);

            ~Sphere() override = default;

            /**
             * @brief Calculates the intersection between a ray and the sphere.
             * 
             * @param ray The ray to test for intersection with the sphere.
             */
            [[nodiscard]] double intersect(const Raytracer::Ray &ray) const override;

            /**
             * @brief Calculates the surface normal at a given point on the sphere.
             * 
             * @param hitPoint The point at which to calculate the surface normal.
             */
            [[nodiscard]] Component::Vector3f getNormal(const Component::Vector3f &hitPoint) const override;

        protected:
        private:
            double _radius;
    };
}