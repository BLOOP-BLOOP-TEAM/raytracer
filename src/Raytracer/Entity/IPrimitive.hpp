/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IPrimitive
*/

#pragma once

#include <memory>
#include "Ray.hpp"
#include "IMaterial.hpp"

namespace Raytracer {
    class IPrimitive {
    public:
        ~IPrimitive() = default;

        virtual bool intersect(Ray rayon) = 0;

        virtual void setMaterial(std::unique_ptr<IMaterial> material) = 0;
    protected:
    private:

    };
};
