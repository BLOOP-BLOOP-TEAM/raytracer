/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight
*/

#include <libconfig.h++>
#include "PointLight.hpp"

Plugin::PointLight::PointLight(const Component::Vector3f &position, const Component::Color &color, float intensity)
        : Raytracer::ALight("PointLight", position, color, intensity)
{
}

Raytracer::IEntity *createEntity(const libconfig::Setting &setting) {
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    Component::Color color(setting["color"][0], setting["color"][1], setting["color"][2]);
    float intensity = setting["intensity"];

    return new Plugin::PointLight(position, color, intensity);
}

const char *getName() {
    return "PointLight";
}

Raytracer::CompType getType() {
    return Raytracer::CompType::LIGHT;
}
