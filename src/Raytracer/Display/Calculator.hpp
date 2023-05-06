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
    /**
     * @brief The Calculator class provides a set of mathematical functions.
     */
    class Calculator {
        public:
            /**
             * @brief Constructor of the Calculator class.
             *
             * @param width the width of the image
             * @param height the height of the image
             * @param entities a reference to a vector of entities
             * @param pixels a reference to a vector of vectors of colors to store the calculated pixels
             */
            Calculator(int width, int height, std::vector<IEntity *> &entities, std::vector<std::vector<Component::Color>>& pixels)
                    : width(width), height(height), entities(entities), pixels(pixels), ambientLightColor(1.0f, 1.0f, 1.0f),
                      ambientLightIntensity(0.1f) {}

            ~Calculator() = default;

            /**
             * @brief Calculates the pixels of the image using the entities and lights.
             */
            void calculatePixels();

        protected:
        private:
            int width;
            int height;
            std::vector<IEntity *> &entities;
            std::vector<std::vector<Component::Color>>& pixels;
            Component::Color ambientLightColor;
            float ambientLightIntensity;

            /**
             * @brief Finds the camera among the entities.
             *
             * @param entities the vector of entities to search through
             */
            ACam *findCam(const std::vector<IEntity *> &entities);

            /**
             * @brief Finds the lights among the entities.
             *
             * @param entities the vector of entities to search through
             */
            std::vector<ALight *> findLights(const std::vector<IEntity *> &entities);

            /**
             * @brief Calculates the ray direction for a given pixel.
             *
             * @param x the x coordinate of the pixel
             * @param y the y coordinate of the pixel
             * @param cam a pointer to the camera to use
             */
            [[nodiscard]] Component::Vector3f getRayDirection(int x, int y, const ACam *cam);

            /**
             * @brief Casts a ray into the scene and calculates the color of the pixel it hits.
             *
             * @param origin the origin of the ray
             * @param direction the direction of the ray
             * @param entities the vector of entities in the scene
             * @param lights the vector of lights in the scene
             * @param recursionDepth the maximum recursion depth for reflections
             */
            Component::Color castRay(const Component::Vector3f &origin, const Component::Vector3f &direction,
                                     const std::vector<IEntity *> &entities,
                                     const std::vector<Raytracer::ALight *> &lights, int recursionDepth = 4) ;

            /**
             *
             * @param origin the origin of the ray
             * @param direction the direction of the ray
             * @param entities the vector of entities to search through
             * @param t_min the minimum distance to consider for the intersection
             */
            Raytracer::IEntity &findClosestEntity(const Component::Vector3f &origin, const Component::Vector3f &direction,
                                                                     const std::vector<IEntity *> &entities, float &t_min) ;

            /**
             * Checks if there is any shadow at a given point
             * @param hit_point The point to check
             * @param hit_normal The normal vector at the point
             * @param light_direction The direction of the light
             * @param entities The entities in the scene
             * @param light The light source to check
             */
            bool checkShadows(const Component::Vector3f &hit_point, const Component::Vector3f &hit_normal,
                              const Component::Vector3f &light_direction, const std::vector<IEntity *> &entities,
                              const Raytracer::ALight &light);

            /**
             * Calculates the resulting pixel color due to lighting
             * @param hit_point The point to illuminate
             * @param hit_normal The normal vector at the point
             * @param material The material at the point
             * @param entities The entities in the scene
             * @param lights The lights in the scene
             */
            Component::Color calculateLighting(const Component::Vector3f &hit_point, const Component::Vector3f &hit_normal,
                                               const Raytracer::AMaterial &material, const std::vector<IEntity *> &entities,
                                               const std::vector<Raytracer::ALight *> &lights);

            /**
             * Calculates the diffuse color of an illuminated point
             * @param hit_point The point to illuminate
             * @param hit_normal The normal vector at the point
             * @param light_direction The direction of the light
             * @param material The material at the point
             * @param light_intensity The intensity of the light
             */
            Component::Color computeDiffuseColor(const Component::Vector3f &hit_point, const Component::Vector3f &hit_normal,
                                                 const Component::Vector3f &light_direction, const AMaterial &material,
                                                 float light_intensity);

            /**
             * Calculates the specular color of an illuminated point
             * @param hit_point The point to illuminate
             * @param hit_normal The normal vector at the point
             * @param light_direction The direction of the light
             * @param material The material at the point
             * @param light The light source to check
             * @param light_intensity The intensity of the light
             */
            Component::Color computeSpecularColor(const Component::Vector3f &hit_point, const Component::Vector3f &hit_normal,
                                                  const Component::Vector3f &light_direction, const AMaterial &material,
                                                  const ALight &light, float light_intensity);

            /**
             * Computes the reflection direction for a given incident and normal vector
             * @param incident The incident vector
             * @param normal The normal vector
             */
            Component::Vector3f getReflectionDirection(const Component::Vector3f &incident, const Component::Vector3f &normal);
    };
};
