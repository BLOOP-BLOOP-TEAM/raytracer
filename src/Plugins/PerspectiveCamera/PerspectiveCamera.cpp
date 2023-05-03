/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PerspectiveCamera
*/

#include <libconfig.h++>
#include "PerspectiveCamera.hpp"

Plugin::PerspectiveCamera::PerspectiveCamera(const Component::Vector3f &position, const Component::Vector3f &rotation, float field_of_view, float aspect_ratio)
        : Raytracer::ACam("PerspectiveCamera", position, rotation, field_of_view, aspect_ratio)
{
}

Raytracer::IEntity *createEntity(const libconfig::Setting &setting) {
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    Component::Vector3f rotation(setting["rotation"][0], setting["rotation"][1], setting["rotation"][2]);
    float field_of_view = setting["field_of_view"];
    float aspect_ratio = setting["aspect_ratio"];

    return new Plugin::PerspectiveCamera(position, rotation, field_of_view, aspect_ratio);
}

const char *getName() {
    return "PerspectiveCamera";
}

Raytracer::CompType getType() {
    return Raytracer::CompType::CAM;
}
