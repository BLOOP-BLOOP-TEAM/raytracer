/*
** EPITECH PROJECT, 2023
** Project
** File description:
** ISkybox
*/

#pragma once

#include "Vector3f.hpp"
#include "Color.hpp"

namespace Raytracer {
    class ISkybox {
        public:
            virtual ~ISkybox() = default;
            [[nodiscard]] virtual std::string getType() const = 0;
            [[nodiscard]] virtual bool isLoaded() = 0;
            [[nodiscard]] virtual Component::Color getColorFromRay(const Component::Vector3f &direction) = 0;
    };
};
