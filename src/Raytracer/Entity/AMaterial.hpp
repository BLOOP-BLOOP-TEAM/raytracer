/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AMaterial
*/

#pragma once

#include <string>

namespace Raytracer {
    class AMaterial {
    public:
        AMaterial(const std::string &type);

        ~AMaterial() = default;

    protected:
    private:
        const std::string _type;
    };
};
