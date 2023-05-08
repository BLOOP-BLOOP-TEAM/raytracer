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

        ReflectMaterial(const Component::Color &baseColor, double diffuseFactor, double reflectivity,
                        double refractivity,
                        double refractiveIndex, const Component::Color &diffuse, double specular, double shininess);

        ~ReflectMaterial() override = default;

    private:
        Component::Color _baseColor;

        [[nodiscard]] Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                      const Component::Vector3f &lightDirection, double lightIntensity,
                                      const Component::Color &ambientLightColor, double ambientLightIntensity) const override;

    };
}
