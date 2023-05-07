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

Plugin::PlaneMaterial::PlaneMaterial(const Component::Color &color1, const Component::Color &color2, double squareSize, double diffuseFactor, double reflectivity, double refractivity, double refractiveIndex,
                                     const Component::Color &diffuse, double specular, double shininess)
        : _color1(color1), _color2(color2), _squareSize(squareSize), Raytracer::AMaterial(PLANEMATERIAL, refractivity, refractiveIndex, reflectivity, diffuseFactor, diffuse, specular, shininess) {}


Component::Color Plugin::PlaneMaterial::computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                            const Component::Vector3f &lightDirection, double lightIntensity,
                                                            const Component::Color &ambientLightColor, double ambientLightIntensity) const
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

    double cosTheta = std::max(0.0, normal.dot(lightDirection));

    Component::Color ambientColor = baseColor * ambientLightIntensity;

    Component::Color color = baseColor * cosTheta;
    color = color + ambientColor;

    return color;
}

Raytracer::IMaterial *createMaterial(const libconfig::Setting &setting)
{
    Component::Color baseColor(setting["baseColor"][0], setting["baseColor"][1], setting["baseColor"][2]);
    Component::Color baseColorSecond(setting["baseColorSecond"][0], setting["baseColorSecond"][1], setting["baseColorSecond"][2]);
    Component::Color colorDiffuse(setting["diffuse"][0], setting["diffuse"][1], setting["diffuse"][2]);
    double squareSize = 0.0f;
    setting.lookupValue("squareSize", squareSize);
    double diffuseFactor = 0.0f;
    double reflectivity = 0.0f;
    double refractivity = 0.0f;
    double refractiveIndex = 0.0f;
    double specular = 0.0f;
    double shininess = 0.0f;


    setting.lookupValue("diffuseFactor", diffuseFactor);
    setting.lookupValue("reflectivity", reflectivity);
    setting.lookupValue("refractivity", refractivity);
    setting.lookupValue("refractiveIndex", refractiveIndex);
    setting.lookupValue("specular", specular);
    setting.lookupValue("shininess", shininess);
    return new Plugin::PlaneMaterial(baseColor, baseColorSecond, squareSize, diffuseFactor, reflectivity, refractivity, refractiveIndex, colorDiffuse ,specular, shininess);
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
