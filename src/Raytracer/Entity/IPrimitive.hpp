/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IPrimitive
*/

#pragma once

#include <memory>
#include "Ray.hpp"
#include "Vector3f.hpp"
#include "Color.hpp"
#include "IMaterial.hpp"

namespace Raytracer {
    class IPrimitive {
    public:
        ~IPrimitive() = default;

        virtual double intersect(const Ray &ray) const = 0 ;

        virtual void setMaterial(IMaterial *material) = 0;

        [[nodiscard]] virtual Component::Vector3f getNormal(const Component::Vector3f &hit_point) const = 0;

        [[nodiscard]] virtual Component::Color getColor(const Component::Vector3f &hit_point) const = 0;

        [[nodiscard]] virtual IMaterial &getMaterial() const = 0;
    protected:
    private:

    };
};
