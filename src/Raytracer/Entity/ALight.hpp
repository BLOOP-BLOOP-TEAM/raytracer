/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ALight
*/

#pragma once

#include <string>
#include "AEntity.hpp"
#include "ILight.hpp"

namespace Raytracer {
    /**
    * @brief The ALight class
    * 
    * The ALight class defines the common methods that all Light objects will have.
    * It extends the ILight class and the AEntity class.
    */
    class ALight : public ILight, public AEntity {
        public:
            /**
             * @brief Constructor for ALight
             * 
             * @param type The type of the light as a string
             * @param position The position of the light as a Vector3f
             * @param color The color of the light as a Color
             * @param intensity The intensity of the light as a double
             */
            ALight(std::string type, const Component::Vector3f &position, const Component::Color &color, double intensity);

            ~ALight() override = default;

            /**
             * @brief Function that gets the color of the light
             */
            [[nodiscard]] const Component::Color& getColor() const override;

            /**
             * @brief Function that gets the intensity of the light
             */
            [[nodiscard]] double getIntensity() const override;

            /**
             * @brief Function that gets the type of the light
             */
            [[nodiscard]] const std::string &getTypeLight() const;
        protected:
        private:
            std::string _typeLight;
            Component::Color _color;
            double _intensity;
    };
};

