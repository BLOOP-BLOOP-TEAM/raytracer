/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SphereApi
*/

#include "SphereApi.hpp"
#include "Sphere.hpp"

Raytracer::IEntity *Plugin::SphereApi::createEntity(const libconfig::Setting &setting) {
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    float radius = setting["radius"];
    return new Sphere(position, radius);
}

const char *Plugin::SphereApi::getName() const {
    return "Sphere";
}

Raytracer::CompType Plugin::SphereApi::getType() const {
    return Raytracer::CompType::PRIMITIVE;
}
