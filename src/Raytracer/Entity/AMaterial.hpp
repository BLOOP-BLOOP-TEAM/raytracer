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
            AMaterial(std::string type, double refractivity, double refractiveIndex, double reflectivity, double diffuseFactor,
                      const Component::Color &diffuse, double specular, double shininess);

            ~AMaterial() override = default;

            const std::string &getType() override;

            [[nodiscard]] Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                    const Component::Vector3f &lightDirection, double lightIntensity,
                                                    const Component::Color &ambientLightColor, double ambientLightIntensity) const override = 0;


            [[nodiscard]] Component::Color getDiffuse() const override;

            [[nodiscard]] double getDiffuseFactor() const override;

            [[nodiscard]] double getSpecular() const override;

            [[nodiscard]] double getShininess() const override;

            [[nodiscard]] double getReflectivity() const override;

            [[nodiscard]] double getRefractivity() const override;

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
