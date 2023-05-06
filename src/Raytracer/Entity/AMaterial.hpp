/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AMaterial
*/

#pragma once

#include <string>
#include "IMaterial.hpp"

namespace Raytracer {
    class AMaterial : public IMaterial {
        public:
            explicit AMaterial(std::string type);

            ~AMaterial() override = default;

            const std::string &getType();

            [[nodiscard]] Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                    const Component::Vector3f &lightDirection, double lightIntensity,
                                                    const Component::Color &ambientLightColor, double ambientLightIntensity) const override = 0;


            [[nodiscard]] Component::Color getDiffuse() const override = 0;

            [[nodiscard]] double getSpecular() const override = 0;

            [[nodiscard]] double getShininess() const override = 0;

            [[nodiscard]] double getReflectivity() const override = 0;
        protected:
            const std::string _type;
    };
}
