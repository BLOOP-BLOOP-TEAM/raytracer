/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera
*/

#include <libconfig.h++>
#include "Api.hpp"
#include "Camera.hpp"

Plugin::Camera::Camera(const Component::Vector3f &position, const Component::Vector3f &rotation, float field_of_view, float aspect_ratio)
        : Raytracer::ACam("camera", position, rotation, field_of_view, aspect_ratio)
{
}
#include <iostream>
Raytracer::IEntity *createEntity(const libconfig::Setting &setting) {

    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    Component::Vector3f rotation(setting["rotation"][0], setting["rotation"][1], setting["rotation"][2]);
    float field_of_view = 0.0f;
    float aspect_ratio = 0.0f;

    setting.lookupValue("fieldOfView", field_of_view);
    setting.lookupValue("aspectRatio", aspect_ratio);
    return new Plugin::Camera(position, rotation, field_of_view, aspect_ratio);
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
