/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera
*/

#include <iostream>
#include <libconfig.h++>
#include "Api.hpp"
#include "Camera.hpp"

static const std::string CAMERA = "camera";

Plugin::Camera::Camera(const Component::Vector3f &position, const Component::Vector3f &rotation, double field_of_view)
        : Raytracer::ACam(CAMERA, position, rotation, field_of_view)
{
}

Raytracer::IEntity *createEntity(const libconfig::Setting &setting)
{
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);

    Component::Vector3f rotation(setting["rotation"][0], setting["rotation"][1], setting["rotation"][2]);
    double field_of_view = 0.0f;

    setting.lookupValue("fieldOfView", field_of_view);
    return new Plugin::Camera(position, rotation, field_of_view);
}

const char *getName()
{
    return CAMERA.c_str();
}

LibType getType() {
    return LibType::ENTITY;
}

void destroyEntity(Raytracer::IEntity *entity)
{
    std::cout << "destroying camera" << std::endl;
    delete entity;
}
