/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Rayon
*/

#pragma once

#include "Vector3f.hpp"

namespace Raytracer {
    /**
     * @brief The Ray data structure
     * 
     * This data structure contains two Vector3F
     * One is called origin and the other one is called direction
     */
    struct Ray {

        /**
         * @brief constructor of Ray data structure
         * 
         * This will build the Ray data structure with the parameters given
         * 
         * @param origin The origin of the Ray
         * @param direction The direction of the Ray
         */
        Ray(Component::Vector3f origin, Component::Vector3f direction);

        Component::Vector3f origin;
        Component::Vector3f direction;

    };
};
