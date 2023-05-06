/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ILight
*/

#pragma once

#include "IPrimitive.hpp"
#include "Color.hpp"

namespace Raytracer {
    /**
     * @brief The ILight class
     * 
     * The ILight class defines the common methods of Light objects.
     */
    class ILight {
        public:
            virtual ~ILight() = default;

            /**
             * @brief Gets the color of the light
             */
            virtual const Component::Color& getColor() const = 0;

            /**
             * @brief Gets the intensity of the light
             */
            virtual double getIntensity() const = 0;
    };
};
