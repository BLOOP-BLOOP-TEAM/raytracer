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
    class ALight : public ILight, public AEntity {
    public:
        ALight(const std::string &type, const Component::Vector3f &position, const Component::Color &color, float intensity);

        ~ALight() = default;

        const Component::Color& getColor() const override;
        float getIntensity() const override;

    protected:
    private:
        std::string _typeLight;
        Component::Color _color;
        float _intensity;
    };
};

