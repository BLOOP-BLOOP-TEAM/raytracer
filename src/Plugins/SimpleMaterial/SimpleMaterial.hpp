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
        SimpleMaterial(const Component::Color &baseColor, double diffuseFactor, double reflectivity);

        ~SimpleMaterial() override = default;


        [[nodiscard]] Component::Color getDiffuse() const override;

        [[nodiscard]] double getSpecular() const override;

        [[nodiscard]] double getShininess() const override;

    private:
        Component::Color _baseColor;
        double _diffuseFactor;
        double _reflectivity;

        [[nodiscard]] Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                      const Component::Vector3f &lightDirection, double lightIntensity,
                                      const Component::Color &ambientLightColor, double ambientLightIntensity) const override;

        [[nodiscard]] double getReflectivity() const override;
    };
}
