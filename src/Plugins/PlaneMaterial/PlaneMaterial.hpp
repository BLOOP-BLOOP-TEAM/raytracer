#pragma once

#include "AMaterial.hpp"

namespace Plugin
{
    /**
     * @brief The PlaneMaterial class represents a material for a plane primitive with a checkered pattern and diffuse color, specular reflection, and shininess.
     */
    class PlaneMaterial : public Raytracer::AMaterial {
        public:
            /**
             * @brief Constructor for PlaneMaterial class.
             * 
             * @param color1 The color of one square in the checkered pattern.
             * @param color2 The color of the other square in the checkered pattern.
             * @param squareSize The size of each square in the checkered pattern.
             * @param diffuseFactor The diffuse factor of the material.
             * @param reflectivity The reflectivity of the material.
             */
            PlaneMaterial(const Component::Color &color1, const Component::Color &color2, float squareSize, float diffuseFactor, float reflectivity);

            ~PlaneMaterial() override = default;

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

            /**
             * @brief Gets the reflectivity of the material.
             */
            [[nodiscard]] float getReflectivity() const override;

        private:
            Component::Color _color1;
            Component::Color _color2;
            float _squareSize;
            float _reflectivity;
            float _diffuseFactor;

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
    };
}
