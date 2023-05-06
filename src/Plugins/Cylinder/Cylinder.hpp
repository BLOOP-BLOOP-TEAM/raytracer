/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder
*/

#pragma once

#include "APrimitive.hpp"
#include "Vector3f.hpp"

namespace Plugin {
    class Cylinder : public Raytracer::APrimitive {
        public:
            Cylinder(const Component::Vector3f &position, float radius, float height,
                    Component::Vector3f &basePoint, Component::Vector3f &topPoint);

            ~Cylinder();

            [[nodiscard]] float intersect(const Raytracer::Ray &ray) const override;

            [[nodiscard]] Component::Vector3f getNormal(const Component::Vector3f &hit_point) const override;

        protected:
        private:
            Component::Vector3f calculateCylinderAxis(const Component::Vector3f &basePoint, const Component::Vector3f &topPoint);

            float _radius;
            float _height;
            Component::Vector3f _axis;
    };
}
