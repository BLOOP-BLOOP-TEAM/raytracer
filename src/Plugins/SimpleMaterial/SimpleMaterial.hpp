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

        Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                      const Component::Vector3f &lightDirection, float lightIntensity) const override;

        Component::Color getDiffuse() const override;

        float getSpecular() const override;

        float getShininess() const override;

    private:
        Component::Color _baseColor;
        float _diffuseFactor;
    };
}
