/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ICam
*/

#pragma once

#include "IPrimitive.hpp"
#include "Vector3f.hpp"

namespace Raytracer {
    class ICam {
    public:
        virtual ~ICam() = default;

        [[nodiscard]] virtual float getFieldOfView() const = 0;

    protected:
    private:
    };
};

