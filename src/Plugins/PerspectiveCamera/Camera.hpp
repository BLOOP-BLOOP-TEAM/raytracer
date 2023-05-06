/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera
*/

#pragma once

#include "ACam.hpp"

namespace Plugin {
    /**
     * @brief The Camera class represents a camera in a 3D scene.
     */
    class Camera : public Raytracer::ACam {
        public:
            /**
             * @brief Constructor for Camera class.
             * 
             * @param position The position of the camera.
             * @param rotation The rotation of the camera.
             * @param fieldOfView The field of view of the camera.
             */
            Camera(const Component::Vector3f &position, const Component::Vector3f &rotation, double fieldOfView);

            ~Camera() override = default;
    };
}
