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
        ALight(std::string type, const Component::Vector3f &position, const Component::Color &color, float intensity);

        ~ALight() override = default;

        [[nodiscard]] const Component::Color& getColor() const override;
        [[nodiscard]] float getIntensity() const override;
        [[nodiscard]] const std::string &getTypeLight() const;

    protected:
    private:
        std::string _typeLight;
        Component::Color _color;
        float _intensity;
    };
};

