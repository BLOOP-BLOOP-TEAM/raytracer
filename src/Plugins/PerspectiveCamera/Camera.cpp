/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera
*/

#include <libconfig.h++>
#include "Api.hpp"
#include "Camera.hpp"

Plugin::Camera::Camera(const Component::Vector3f &position, const Component::Vector3f &rotation, const float fieldOfView, const Component::Vector3f &resolution)
        : Raytracer::ACam("camera", position, rotation, fieldOfView, resolution)
{
}

Raytracer::IEntity *createEntity(const libconfig::Setting &setting) {

    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    Component::Vector3f rotation(setting["rotation"][0], setting["rotation"][1], setting["rotation"][2]);
    float fieldOfView = 0.0f;
    Component::Vector3f resolution;
    libconfig::Setting &res = setting["resolution"];

    setting.lookupValue("fieldOfView", fieldOfView);
    res.lookupValue("width", resolution.x);
    res.lookupValue("height", resolution.y);
    return new Plugin::Camera(position, rotation, fieldOfView, resolution);
}
const char *getName() {
    return "camera";
}

LibType getType() {
    return LibType::ENTITY;
}

void destroyEntity(Raytracer::IEntity *entity) {
    delete entity;
}
