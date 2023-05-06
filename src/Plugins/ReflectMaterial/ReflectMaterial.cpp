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
#include "ReflectMaterial.hpp"
#include "AMaterial.hpp"

static const std::string REFLECTMATERIAL = "ReflectMaterial";

Plugin::ReflectMaterial::ReflectMaterial(const Component::Color &baseColor, float diffuseFactor, float reflectivity)
        : Raytracer::AMaterial(REFLECTMATERIAL), _baseColor(baseColor), _diffuseFactor(diffuseFactor), _reflectivity(reflectivity) {}

Component::Color Plugin::ReflectMaterial::computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                      const Component::Vector3f &lightDirection, float lightIntensity,
                                                      const Component::Color &ambientLightColor,
                                                      float ambientLightIntensity) const
{
    float cosTheta = std::max(0.0f, normal.dot(lightDirection));


    Component::Color ambientColor = _baseColor * ambientLightIntensity;

    Component::Color color = _baseColor * (_diffuseFactor * cosTheta);
    color = color + ambientColor;

    return color;
}


Component::Color Plugin::ReflectMaterial::getDiffuse() const
{
    return _baseColor;
}

float Plugin::ReflectMaterial::getSpecular() const
{
    return 0.0f;
}

float Plugin::ReflectMaterial::getShininess() const
{
    return 1.0f;
}

float Plugin::ReflectMaterial::getReflectivity() const
{
    return _reflectivity;
}

Raytracer::IMaterial *createMaterial(const libconfig::Setting &setting)
{
    Component::Color baseColor(setting["baseColor"][0], setting["baseColor"][1], setting["baseColor"][2]);
    float diffuseFactor = 0.0f;
    float reflectivity = 0.0f;


    setting.lookupValue("diffuseFactor", diffuseFactor);
    setting.lookupValue("reflectivity", reflectivity);
    return new Plugin::ReflectMaterial(baseColor, diffuseFactor, reflectivity);
}

const char *getName()
{
    return REFLECTMATERIAL.c_str();
}

LibType getType()
{
    return LibType::MATERIAL;
}

void destroyMaterial(Raytracer::IMaterial *material)
{
    delete material;
}
