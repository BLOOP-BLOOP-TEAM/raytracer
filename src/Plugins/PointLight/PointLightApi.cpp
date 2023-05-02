/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PointLightApi
*/

#include "PointLightApi.hpp"
#include "PointLight.hpp"

Raytracer::IEntity *Plugin::PointLightApi::createEntity(const libconfig::Setting &setting) {
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    Component::Color color(setting["color"][0], setting["color"][1], setting["color"][2]);
    float intensity = setting["intensity"];

    return new Plugin::PointLight(position, color, intensity);
}

const char *Plugin::PointLightApi::getName() const {
    return "PointLight";
}

Raytracer::CompType Plugin::PointLightApi::getType() const {
    return Raytracer::CompType::LIGHT;
}