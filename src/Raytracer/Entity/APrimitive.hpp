/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** APrimitive
*/

#pragma once

#include "IPrimitive.hpp"
#include "AEntity.hpp"

namespace Raytracer {
    class APrimitive : public IPrimitive, public AEntity {
    public:
        APrimitive();

        ~APrimitive();

    protected:
    private:
    };
};
