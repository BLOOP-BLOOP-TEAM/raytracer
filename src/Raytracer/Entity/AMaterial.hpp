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

            [[nodiscard]] Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal, const Component::Vector3f &lightDirection, float lightIntensity) const override;

            [[nodiscard]] Component::Color getDiffuse() const override = 0;

            [[nodiscard]] float getSpecular() const override = 0;

            [[nodiscard]] float getShininess() const override = 0;
        protected:
            const std::string _type;
    };
}
