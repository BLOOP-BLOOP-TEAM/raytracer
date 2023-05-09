/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DirectionalLight
*/

#include <iostream>
#include <libconfig.h++>
#include "Api.hpp"
#include "DirectionalLight.hpp"

static const std::string DIRECTIONALLIGHT = "DirectionalLight";

Plugin::DirectionalLight::DirectionalLight(const Component::Vector3f &position, const Component::Vector3f &rotation, const Component::Color &color, double intensity, const Component::Vector3f &direction)
        : Raytracer::ALight(DIRECTIONALLIGHT, position, rotation, color, intensity) , _direction(direction)
{
}

bool Plugin::DirectionalLight::isIlluminating(const Component::Vector3f &origin, const Component::Vector3f &direction) const
{
    return direction.dot(_direction) > 0;
}

Raytracer::IEntity *createEntity(const libconfig::Setting &setting)
{
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    Component::Vector3f rotation(setting["rotation"][0], setting["rotation"][1], setting["rotation"][2]);
    Component::Vector3f direction(setting["direction"][0], setting["direction"][1], setting["direction"][2]);
    Component::Color color(setting["color"][0], setting["color"][1], setting["color"][2]);
    double intensity = 0.0f;

    setting.lookupValue("intensity", intensity);
    return new Plugin::DirectionalLight(position, rotation, color, intensity, direction);
}

const char *getName()
{
    return DIRECTIONALLIGHT.c_str();
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
