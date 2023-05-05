/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SimpleMaterial
*/

#pragma once

#include "AMaterial.hpp"
#include "Ray.hpp"
#include "Vector3f.hpp"

namespace Plugin {
    class SimpleMaterial : public Raytracer::AMaterial {
    public:
        SimpleMaterial(const Component::Color &baseColor, float diffuseFactor);

        ~SimpleMaterial() override = default;

        [[nodiscard]] Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                      const Component::Vector3f &lightDirection, float lightIntensity) const override;

        [[nodiscard]] Component::Color getDiffuse() const override;

        [[nodiscard]] float getSpecular() const override;

        [[nodiscard]] float getShininess() const override;

    private:
        Component::Color _baseColor;
        float _diffuseFactor;
    };
}
