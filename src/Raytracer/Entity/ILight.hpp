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

        virtual const Component::Color& getColor() const = 0;
        virtual float getIntensity() const = 0;

    protected:
    private:
    };
};
