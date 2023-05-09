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
    /**
     * @brief The AMaterial class
     * 
     * The AMaterial class defines the common methods that all Material objects will have.
     * It extends the IMaterial class.
     */
    class AMaterial : public IMaterial {
        public:
            /**
             * @brief Constructor for AMaterial
             * 
             * @param type The type of the material as a string
             */
            AMaterial(std::string type, double refractivity, double refractiveIndex, double reflectivity, double diffuseFactor,
                      const Component::Color &diffuse, double specular, double shininess);

            ~AMaterial() override = default;

            /**
             * @brief Function that gets the type of the material
             */
            const std::string &getType() override;

            /**
             * @brief Compute the color of the object at the given point
             * 
             * @param hitPoint The point where the object was hit
             * @param normal The normal vector of the object at the hit point
             * @param lightDirection The direction of the incoming light
             * @param lightIntensity The intensity of the incoming light
             * @param ambientLightColor The color of the ambient light
             * @param ambientLightIntensity The intensity of the ambient light
             */
            [[nodiscard]] Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                    const Component::Vector3f &lightDirection, double lightIntensity,
                                                    const Component::Color &ambientLightColor, double ambientLightIntensity) const override = 0;

            /**
             * @brief Get the diffuse color of the material
             */
            [[nodiscard]] Component::Color getDiffuse() const override = 0;

            /**
             * @brief Get the specular coefficient of the material
             */
            [[nodiscard]] double getSpecular() const override = 0;

            /**
             * @brief Get the diffuse factor of the material
             */
            [[nodiscard]] double getDiffuseFactor() const override;

            /**
             * @brief Get the shininess coefficient of the material
             */
            [[nodiscard]] double getShininess() const override = 0;

            /**
             * @brief Get the reflectivity of the material
             */
            [[nodiscard]] double getReflectivity() const override = 0;

            /**
             * @brief Get the refractivity of the material
             */
            [[nodiscard]] double getRefractivity() const override;

            /**
             * @brief Get the refractive index of the material
             */
            [[nodiscard]] double getRefractiveIndex() const override;

        protected:
            const std::string _type;
            double _refractivity;
            double _refractiveIndex;
            double _reflectivity;
            double _diffuseFactor;
            Component::Color _diffuse;
            double _specular;
            double _shininess;
    };
}
