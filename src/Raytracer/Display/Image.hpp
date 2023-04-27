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

        Component::Color get_pixel(int x, int y) const;

        void write_ppm(const std::string &filename) const;

        void calculateImage(std::vector<std::unique_ptr<IEntity>> &entities);

    private:
        int width;
        int height;
        static const int MAX_COLOR = 255;
        std::vector<std::vector<Component::Color>> pixels;

        ACam& findCam(const std::vector<std::unique_ptr<IEntity>> &entities);
        std::vector<std::reference_wrapper<ALight>> findLights(const std::vector<std::unique_ptr<IEntity>> &entities);

        Component::Vector3f getRayDirection(int x, int y, int screenWidth, int screenHeight, const ACam *camera);
        Component::Color castRay(const Component::Vector3f &origin, const Component::Vector3f &direction,
                                 const std::vector<std::unique_ptr<IEntity>> &entities,
                                 const std::vector<ALight*> &lights);
    };
}
