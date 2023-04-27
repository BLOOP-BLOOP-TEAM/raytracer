/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ACam
*/

#include "ACam.hpp"

// ACam.cpp
#include "ACam.hpp"

namespace Raytracer {
    ACam::ACam(const std::string &typeCam, const Component::Vector3f &position, float fieldOfView, float aspectRatio)
            : AEntity(Raytracer::CompType::CAM, position), _typeCam(typeCam), _fieldOfView(fieldOfView), _aspectRatio(aspectRatio) {}

    float ACam::getFieldOfView() const {
        return _fieldOfView;
    }

    float ACam::getAspectRatio() const {
        return _aspectRatio;
    }
}

