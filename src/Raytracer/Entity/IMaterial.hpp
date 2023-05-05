/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IMaterial
*/

#pragma once

#include "Color.hpp"
#include "Vector3f.hpp"

namespace Raytracer {

    /**
     * @brief the IMaterial class
     * 
     * This class defines all the common method of Materials objects
     */
    class IMaterial {
        public:
            virtual ~IMaterial() = default;

            /**
             * TODO
             */
            virtual Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal, const Component::Vector3f &lightDirection, float lightIntensity) const = 0;

            virtual Component::Color getDiffuse() const = 0;

            virtual float getSpecular() const = 0;

            virtual float getShininess() const = 0;
    };
}
