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
#include "SimpleMaterial.hpp"
#include "AMaterial.hpp"

static const std::string SIMPLEMATERIAL = "SimpleMaterial";

Plugin::SimpleMaterial::SimpleMaterial(const Component::Color &baseColor, double diffuseFactor, double reflectivity, double refractivity, double refractiveIndex,
const Component::Color &diffuse, double specular, double shininess)
        : Raytracer::AMaterial(SIMPLEMATERIAL, refractivity, refractiveIndex, reflectivity, diffuseFactor, diffuse, specular, shininess), _baseColor(baseColor) {}

Component::Color Plugin::SimpleMaterial::computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                      const Component::Vector3f &lightDirection, double lightIntensity,
                                                      const Component::Color &ambientLightColor,
                                                      double ambientLightIntensity) const
{
    double cosTheta = std::max(0.0, normal.dot(lightDirection));

    // Prendre en compte l'intensité de la lumière dans la couleur ambiante
    Component::Color ambientColor = _baseColor * ambientLightIntensity * lightIntensity;

    // Prendre en compte l'intensité de la lumière, la shininess et le diffuseFactor dans la couleur diffuse
    Component::Color color = _baseColor * (_diffuseFactor * cosTheta * lightIntensity);

    // Ajouter la couleur ambiante à la couleur diffuse
    color = color + ambientColor;

    return color;
}

Raytracer::IMaterial *createMaterial(const libconfig::Setting &setting)
{
    Component::Color baseColor(setting["baseColor"][0], setting["baseColor"][1], setting["baseColor"][2]);
    Component::Color colorDiffuse(setting["diffuse"][0], setting["diffuse"][1], setting["diffuse"][2]);
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

    return new Plugin::SimpleMaterial(baseColor, diffuseFactor, reflectivity, refractivity, refractiveIndex, colorDiffuse, specular, shininess);
}

const char *getName()
{
    return SIMPLEMATERIAL.c_str();
}

LibType getType()
{
    return LibType::MATERIAL;
}

void destroyMaterial(Raytracer::IMaterial *material)
{
    delete material;
}
