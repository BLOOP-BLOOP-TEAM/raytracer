/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PerspectiveCameraApi
*/

#include "PerspectiveCamera.hpp"
#include "PerspectiveCameraApi.hpp"

Raytracer::IEntity *Plugin::PerspectiveCameraApi::createEntity(const libconfig::Setting &setting) {
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    Component::Vector3f rotation(setting["rotation"][0], setting["rotation"][1], setting["rotation"][2]);
    float field_of_view = setting["field_of_view"];
    float aspect_ratio = setting["aspect_ratio"];

    return new Plugin::PerspectiveCamera(position, rotation, field_of_view, aspect_ratio);
}

const char *Plugin::PerspectiveCameraApi::getName() const {
    return "PerspectiveCamera";
}

Raytracer::CompType Plugin::PerspectiveCameraApi::getType() const {
    return Raytracer::CompType::CAM;
}
