/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere
*/

#pragma once

#include "APrimitive.hpp"
#include "Ray.hpp"
#include "Vector3f.hpp"

namespace Plugin {
class Sphere : public Raytracer::APrimitive {
    public:
        Sphere(const Component::Vector3f &position, float radius);

        ~Sphere() = default;

        float intersect(const Raytracer::Ray &ray) override;

        Component::Vector3f getNormal(const Component::Vector3f &hit_point) const override;

    protected:
    private:
        float _radius;
    };
}
