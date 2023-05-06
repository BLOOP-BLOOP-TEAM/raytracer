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
    /**
     * @brief The ReflectMaterial class represents a material with a reflective surface,
     * in addition to diffuse color, specular reflection, and shininess.
     */
    class ReflectMaterial : public Raytracer::AMaterial {
        public:
            /**
             * @brief Constructor for ReflectMaterial class.
             * 
             * @param baseColor The base color of the material.
             * @param diffuseFactor The diffuse factor of the material.
             * @param reflectivity The reflectivity of the material.
             */
            ReflectMaterial(const Component::Color &baseColor, float diffuseFactor, float reflectivity);

            ~ReflectMaterial() override = default;

            /**
             * @brief Gets the diffuse color of the material.
             */
            [[nodiscard]] Component::Color getDiffuse() const override;

            /**
             * @brief Gets the specular reflection factor of the material.
             */
            [[nodiscard]] float getSpecular() const override;

            /**
             * @brief Gets the shininess of the material.
             */
            [[nodiscard]] float getShininess() const override;

        private:
            Component::Color _baseColor;
            float _diffuseFactor;
            float _reflectivity;

            /**
             * @brief Computes the color of the material at a given point, taking into account the lighting and ambient color.
             * 
             * @param hitPoint The point at which to compute the color.
             * @param normal The surface normal at the point.
             * @param lightDirection The direction of the light.
             * @param lightIntensity The intensity of the light.
             * @param ambientLightColor The color of the ambient light.
             * @param ambientLightIntensity The intensity of the ambient light.
             */
            [[nodiscard]] Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                          const Component::Vector3f &lightDirection, float lightIntensity,
                                          const Component::Color &ambientLightColor, float ambientLightIntensity) const override;

            /**
             * @brief Gets the reflectivity of the material.
             */
            [[nodiscard]] float getReflectivity() const override;
    };
}