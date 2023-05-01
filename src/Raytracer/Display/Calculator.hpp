/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Calculator
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

#pragma once

namespace Raytracer {
    class Calculator {
    public:
        Calculator(int width, int height, std::vector<IEntity *> &entities, std::vector<std::vector<Component::Color>>& pixels)
                : width(width), height(height), entities(entities), pixels(pixels) {}

        ~Calculator() = default;

        void calculatePixels();

    protected:
    private:
        int width;
        int height;
        std::vector<IEntity *> &entities;
        std::vector<std::vector<Component::Color>>& pixels;

        static ACam& findCam(const std::vector<IEntity *> &entities);

        static std::vector<std::shared_ptr<ALight>> findLights(const std::vector<IEntity *> &entities);

        [[nodiscard]] Component::Vector3f getRayDirection(int x, int y, const ACam &cam) const;

        static Component::Color castRay(const Component::Vector3f &origin, const Component::Vector3f &direction,
                                 const std::vector<IEntity *> &entities,
                                 const std::vector<std::shared_ptr<Raytracer::ALight>> &lights) ;

        static Raytracer::IEntity &findClosestEntity(const Component::Vector3f &origin, const Component::Vector3f &direction,
                                                                     const std::vector<IEntity *> &entities, float &t_min) ;

        static bool checkShadows(const Component::Vector3f &hit_point, const Component::Vector3f &hit_normal,
                                                 const Component::Vector3f &light_direction, const std::vector<IEntity *> &entities,
                                                 const std::shared_ptr<Raytracer::ALight> &light) ;

    };
};
