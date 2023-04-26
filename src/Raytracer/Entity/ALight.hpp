/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ALight
*/

#pragma once

#include "AEntity.hpp"
#include "ILight.hpp"

namespace Raytracer {
    class ALight : public ILight, public AEntity {
    public:
        ALight();

        ~ALight();

    protected:
    private:
    };
};