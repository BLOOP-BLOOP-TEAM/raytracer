/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Image
*/

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
#include "Color.hpp"
#include "IEntity.hpp"
#include "ALight.hpp"
#include "ACam.hpp"

namespace Raytracer {

    class Image {
    public:
        Image(int width, int height);

        [[nodiscard]] Component::Color getPixel(unsigned int x, unsigned int y) const;

        void writePPM(const std::string &filename) const;

        void calculateImage(std::vector<IEntity *> &entities);

    private:
        int width;
        int height;
        static const int MAX_COLOR = 255;
        std::vector<std::vector<Component::Color>> pixels;
    };
}
