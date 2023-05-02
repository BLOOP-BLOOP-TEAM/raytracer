/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AMaterial
*/

#pragma once

#include <string>
#include "IMaterial.hpp"

namespace Raytracer {
    class AMaterial : public IMaterial {
        public:
            explicit AMaterial(std::string type);

            ~AMaterial() override = default;

            const std::string &getType();
        protected:
            const std::string _type;
    };
}
