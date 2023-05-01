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

        [[nodiscard]] Component::Color get_pixel(int x, int y) const;

        void write_ppm(const std::string &filename) const;

        void calculateImage(std::vector<IEntity *> &entities);

    private:
        int width;
        int height;
        static const int MAX_COLOR = 255;
        std::vector<std::vector<Component::Color>> pixels;

        static ACam& findCam(const std::vector<IEntity *> &entities);
        static std::vector<std::shared_ptr<ALight>> findLights(const std::vector<IEntity *> &entities);

        static Component::Vector3f getRayDirection(int x, int y, int screenWidth, int screenHeight);
        static Component::Color castRay(const Component::Vector3f &origin, const Component::Vector3f &direction,
                                 const std::vector<IEntity *> &entities,
                                 const std::vector<std::shared_ptr<ALight>> &lights);
    };
}
