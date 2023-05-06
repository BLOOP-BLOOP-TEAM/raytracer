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
    class ReflectMaterial : public Raytracer::AMaterial {
    public:
        ReflectMaterial(const Component::Color &baseColor, float diffuseFactor, float reflectivity);

        ~ReflectMaterial() override = default;


        [[nodiscard]] Component::Color getDiffuse() const override;

        [[nodiscard]] float getSpecular() const override;

        [[nodiscard]] float getShininess() const override;

    private:
        Component::Color _baseColor;
        float _diffuseFactor;
        float _reflectivity;

        [[nodiscard]] Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                      const Component::Vector3f &lightDirection, float lightIntensity,
                                      const Component::Color &ambientLightColor, float ambientLightIntensity) const override;

        [[nodiscard]] float getReflectivity() const override;
    };
}
