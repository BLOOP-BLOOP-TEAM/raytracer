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
            explicit AMaterial(std::string type);

            ~AMaterial() override = default;

            /**
             * @brief Function that gets the type of the material
             */
            const std::string &getType();

            [[nodiscard]] Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                    const Component::Vector3f &lightDirection, float lightIntensity,
                                                    const Component::Color &ambientLightColor, float ambientLightIntensity) const override = 0;


            [[nodiscard]] Component::Color getDiffuse() const override = 0;

            [[nodiscard]] float getSpecular() const override = 0;

            [[nodiscard]] float getShininess() const override = 0;

            [[nodiscard]] float getReflectivity() const override = 0;
        protected:
            const std::string _type;
    };
}
