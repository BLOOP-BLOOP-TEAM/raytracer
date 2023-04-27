/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IMaterial
*/

#pragma once

#include <string>

namespace Raytracer {
    class IMaterial {
    public:

        virtual ~IMaterial() = default;
    protected:
    private:
        std::string type;
    };
};