/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SimpleMaterial
*/

#include <libconfig.h++>
#include <iostream>
#include "Api.hpp"
#include "IEntity.hpp"
#include "PlaneMaterial.hpp"
#include "AMaterial.hpp"

static const std::string PLANEMATERIAL = "PlaneMaterial";

Plugin::PlaneMaterial::PlaneMaterial(const Component::Color &color1, const Component::Color &color2, float squareSize, float diffuseFactor, float reflectivity)
        : _color1(color1), _color2(color2), _squareSize(squareSize), Raytracer::AMaterial(PLANEMATERIAL), _diffuseFactor(diffuseFactor), _reflectivity(reflectivity) {}


Component::Color Plugin::PlaneMaterial::computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                            const Component::Vector3f &lightDirection, float lightIntensity,
                                                            const Component::Color &ambientLightColor, float ambientLightIntensity) const
{
    int ix = static_cast<int>(floor(hitPoint.x / _squareSize));
    int iz = static_cast<int>(floor(hitPoint.z / _squareSize));

    Component::Color baseColor;

    if ((ix + iz) % 2 == 0)
    {
        baseColor = _color1;
    }
    else
    {
        baseColor = _color2;
    }

    float cosTheta = std::max(0.0f, normal.dot(lightDirection));

    Component::Color ambientColor = baseColor * ambientLightIntensity;

    Component::Color color = baseColor * cosTheta;
    color = color + ambientColor;

    return color;
}


Component::Color Plugin::PlaneMaterial::getDiffuse() const
{
    return _color1;
}

float Plugin::PlaneMaterial::getSpecular() const
{
    return 0.0f;
}

float Plugin::PlaneMaterial::getShininess() const
{
    return 1.0f;
}

float Plugin::PlaneMaterial::getReflectivity() const
{
    return _reflectivity;
}

Raytracer::IMaterial *createMaterial(const libconfig::Setting &setting)
{
    Component::Color baseColor(setting["baseColor"][0], setting["baseColor"][1], setting["baseColor"][2]);
    Component::Color baseColorSecond(setting["baseColorSecond"][0], setting["baseColorSecond"][1], setting["baseColorSecond"][2]);
    float squareSize = 0.0f;
    setting.lookupValue("squareSize", squareSize);
    float diffuseFactor = 0.0f;
    float reflectivity = 0.0f;


    setting.lookupValue("diffuseFactor", diffuseFactor);
    setting.lookupValue("reflectivity", reflectivity);
    return new Plugin::PlaneMaterial(baseColor, baseColorSecond, squareSize, diffuseFactor, reflectivity);
}

const char *getName()
{
    return PLANEMATERIAL.c_str();
}

LibType getType()
{
    return LibType::MATERIAL;
}

void destroyMaterial(Raytracer::IMaterial *material)
{
    delete material;
}
