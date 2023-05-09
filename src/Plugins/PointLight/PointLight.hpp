/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight
*/

#pragma once

#include "ALight.hpp"

namespace Plugin {
    /**
     * @brief The PointLight class represents a point light source in a 3D scene.
     */
    class PointLight : public Raytracer::ALight {
    public:
        /**
         * @brief Constructor for PointLight class.
         * 
         * @param position The position of the light source.
         * @param color The color of the light source.
         * @param intensity The intensity of the light source.
         */
        PointLight(const Component::Vector3f &position, const Component::Vector3f &rotation, const Component::Color &color, double intensity);

        ~PointLight() override = default;

        /**
         * @brief Check if the light is illuminating a point in the scene
         * 
         * @param origin The origin of the ray
         * @param direction The direction of the ray
         */
        [[nodiscard]] bool isIlluminating(const Component::Vector3f &origin, const Component::Vector3f &direction) const override;
    };
}
