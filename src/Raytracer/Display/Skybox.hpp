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
        explicit Skybox(const std::string& filename);

        ~Skybox();
        Component::Color getColorFromRay(const Component::Vector3f &direction);

    private:
        int m_width, m_height, m_channels;
        std::vector<unsigned char> m_data;

        unsigned char* getPixel(float u, float v);
    };
}
