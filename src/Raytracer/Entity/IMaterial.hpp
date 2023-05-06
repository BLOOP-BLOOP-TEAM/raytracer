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
     * @brief The IMaterial class
     * 
     * The IMaterial class defines all the common methods of Material objects.
     */
    class IMaterial {
        public:
            virtual ~IMaterial() = default;

            /**
             * @brief Computes the color of a pixel based on the material's properties
             * 
             * Computes the color of a pixel using the hitPoint, normal, lightDirection, and
             * lightIntensity parameters.
             * 
             * @param hitPoint The point of intersection between the ray and the object
             * @param normal The normal vector of the object's surface at the intersection point
             * @param lightDirection The direction of the light source
             * @param lightIntensity The intensity of the light source
             */
            [[nodiscard]] virtual Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                    const Component::Vector3f &lightDirection, double lightIntensity,
                                                    const Component::Color &ambientLightColor, double ambientLightIntensity) const = 0;

            /**
             * @brief Gets the diffuse color of the material
             */
            virtual Component::Color getDiffuse() const = 0;

            /**
             * @brief Gets the specular coefficient of the material
             */
            virtual double getSpecular() const = 0;

            /**
             * @brief Gets the shininess of the material
             */
            virtual double getShininess() const = 0;

            [[nodiscard]] virtual double getReflectivity() const = 0;
    };
}
