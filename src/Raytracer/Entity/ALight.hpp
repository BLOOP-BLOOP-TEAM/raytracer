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
        ALight(const std::string &type, const Component::Vector3f &position);

        ~ALight() = default;

    protected:
    private:
        std::string _typeLight;
    };
};
