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

    class IMaterial {
        public:
            virtual ~IMaterial() = default;

            [[nodiscard]] virtual Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                    const Component::Vector3f &lightDirection, double lightIntensity,
                                                    const Component::Color &ambientLightColor, double ambientLightIntensity) const = 0;

            [[nodiscard]] virtual Component::Color getDiffuse() const = 0;

            [[nodiscard]] virtual double getSpecular() const = 0;

            [[nodiscard]] virtual double getShininess() const = 0;

            [[nodiscard]] virtual double getReflectivity() const = 0;
    };
}
