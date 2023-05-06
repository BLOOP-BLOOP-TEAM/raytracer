/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Skybox
*/

#pragma once

#include <iostream>
#include <jpeglib.h>
#include <jerror.h>
#include <vector>
#include "Color.hpp"
#include "Vector3f.hpp"

namespace Raytracer {

    class Skybox {

    public:
        explicit Skybox(const std::string &filename);

        [[nodiscard]] Component::Color getColor(const Component::Vector3f &direction) const;

    private:
        std::vector<Component::Color> _skyboxData;

        int _skyboxWidth;
        int _skyboxHeight;

        void load(const std::string &filename);
    };
}