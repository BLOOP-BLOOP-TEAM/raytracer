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
#include "AMaterial.hpp"

#pragma once

namespace Raytracer {
    class Calculator {
    public:
        Calculator(int width, int height, std::vector<IEntity *> &entities, std::vector<std::vector<Component::Color>>& pixels)
                : width(width), height(height), entities(entities), pixels(pixels), ambientLightColor(1.0f, 1.0f, 1.0f),
                  ambientLightIntensity(0.1f) {}

        ~Calculator() = default;

        void calculatePixels();

    protected:
    private:
        int width;
        int height;
        std::vector<IEntity *> &entities;
        std::vector<std::vector<Component::Color>>& pixels;
        Component::Color ambientLightColor;
        double ambientLightIntensity;

        ACam *findCam(const std::vector<IEntity *> &entities);

        std::vector<ALight *> findLights(const std::vector<IEntity *> &entities);

        [[nodiscard]] Component::Vector3f getRayDirection(int x, int y, const ACam *cam);

        Component::Color castRay(const Component::Vector3f &origin, const Component::Vector3f &direction,
                                 const std::vector<IEntity *> &entities,
                                 const std::vector<Raytracer::ALight *> &lights, int recursionDepth = 4) ;

        Raytracer::IEntity &findClosestEntity(const Component::Vector3f &origin, const Component::Vector3f &direction,
                                                                     const std::vector<IEntity *> &entities, double &t_min) ;

        bool checkShadows(const Component::Vector3f &hit_point, const Component::Vector3f &hit_normal,
                                                 const Component::Vector3f &light_direction, const std::vector<IEntity *> &entities,
                                                 const Raytracer::ALight &light) ;

        Component::Color calculateLighting(const Component::Vector3f &hit_point, const Component::Vector3f &hit_normal,
                                                  const Raytracer::AMaterial &material, const std::vector<IEntity *> &entities,
                                                  const std::vector<Raytracer::ALight *> &lights);


        Component::Color
        computeDiffuseColor(const Component::Vector3f &hit_point, const Component::Vector3f &hit_normal,
                            const Component::Vector3f &light_direction, const AMaterial &material,
                            double light_intensity);

        Component::Color
        computeSpecularColor(const Component::Vector3f &hit_point, const Component::Vector3f &hit_normal,
                             const Component::Vector3f &light_direction, const AMaterial &material,
                             const ALight &light, double light_intensity);

        Component::Vector3f
        getReflectionDirection(const Component::Vector3f &incident, const Component::Vector3f &normal);

        Component::Color getAverageColor(int x, int y, const ACam *camera, const std::vector<IEntity *> &entities,
                                         const std::vector<Raytracer::ALight *> &lights, int subPixelsPerAxis);

        Component::Vector3f
        getRefractionDirection(const Component::Vector3f &incident, const Component::Vector3f &normal,
                               double refractiveIndex);
    };
};
