/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IPrimitive
*/

#pragma once

#include <memory>
#include "Ray.hpp"
#include "Vector3f.hpp"
#include "Color.hpp"
#include "IMaterial.hpp"

namespace Raytracer {
    /**
     * @brief The IPrimitive class
     * 
     * This class defines all the common methods that a Primitive will have
     */
    class IPrimitive {
        public:
            ~IPrimitive() = default;

            /**
             * @brief function that checks for an intersection with a ray
             * 
             * Calculates whether the specified ray intersects with the object.
             * 
             * @param ray The Ray object to check for intersection
             */
            virtual double intersect(const Ray &ray) const = 0 ;

            /**
             * @brief function that set material
             * 
             * This function will set a material to any object of IPrimitive
             * 
             * @param material pointer on IMaterial object to set
             */
            virtual void setMaterial(IMaterial *material) = 0;

            /**
             * @brief function that get the normal
             * 
             * This function take a parameter a hit point is used to calculate
             * the normal of the IPrimitive object with the help of his position
             * 
             * @param hitPoint a Vector3f object that is used for calculate the normal
             */
            [[nodiscard]] virtual Component::Vector3f getNormal(const Component::Vector3f &hitPoint) const = 0;

            /**
             * @brief function that get color
             * 
             * This function is used to calculate the color of a pixel
             * with the help of a hit point
             * 
             * @param hitPoint a Vector3f object that is used to calculate the color of the pixel
             */
            [[nodiscard]] virtual Component::Color getColor(const Component::Vector3f &hitPoint) const = 0;

            /**
             * @brief function that get material
             * 
             * This function is used to get the material of an IPrimitive object
             */
            [[nodiscard]] virtual IMaterial &getMaterial() const = 0;

    };
};
