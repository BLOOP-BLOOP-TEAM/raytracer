/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PlaneApi
*/

#include "PlaneApi.hpp"
#include "Plane.hpp"

Raytracer::IEntity *Plugin::PlaneApi::createEntity(const libconfig::Setting &setting) {
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    Component::Vector3f normal(setting["normal"][0], setting["normal"][1], setting["normal"][2]);
    return new Plugin::Plane(position, normal);
}

const char *Plugin::PlaneApi::getName() const {
    return "Plane";
}

Raytracer::CompType Plugin::PlaneApi::getType() const {
    return Raytracer::CompType::PRIMITIVE;
}
