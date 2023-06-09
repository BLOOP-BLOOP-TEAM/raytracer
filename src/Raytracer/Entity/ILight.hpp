/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ILight
*/

#pragma once

#include "IPrimitive.hpp"
#include "Color.hpp"

namespace Raytracer {
    class ILight {
    public:
        virtual ~ILight() = default;

        [[nodiscard]] virtual const Component::Color& getColor() const = 0;
        [[nodiscard]] virtual double getIntensity() const = 0;
        [[nodiscard]] virtual bool isIlluminating(const Component::Vector3f &origin, const Component::Vector3f &direction) const = 0;

    protected:
    private:
    };
};
