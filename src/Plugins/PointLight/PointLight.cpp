/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight
*/

#include <iostream>
#include <libconfig.h++>
#include "Api.hpp"
#include "PointLight.hpp"

static const std::string POINTLIGHT = "PointLight";

Plugin::PointLight::PointLight(const Component::Vector3f &position, const Component::Vector3f &rotation, const Component::Color &color, double intensity)
        : Raytracer::ALight(POINTLIGHT, position, rotation, color, intensity)
{
}

bool Plugin::PointLight::isIlluminating(const Component::Vector3f &origin, const Component::Vector3f &direction) const
{
    return true;
}

Raytracer::IEntity *createEntity(const libconfig::Setting &setting)
{
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    Component::Vector3f rotation(setting["rotation"][0], setting["rotation"][1], setting["rotation"][2]);
    Component::Color color(setting["color"][0], setting["color"][1], setting["color"][2]);
    double intensity = 0.0f;

    setting.lookupValue("intensity", intensity);
    return new Plugin::PointLight(position, rotation, color, intensity);
}

const char *getName()
{
    return POINTLIGHT.c_str();
}

LibType getType()
{
    return LibType::ENTITY;
}

void destroyEntity(Raytracer::IEntity *entity)
{
    std::cout << "destroying light" << std::endl;
    delete entity;
}
