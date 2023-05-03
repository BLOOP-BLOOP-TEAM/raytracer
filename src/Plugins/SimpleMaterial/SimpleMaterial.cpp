/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SimpleMaterial
*/

#include <libconfig.h++>
#include "IEntity.hpp"
#include "SimpleMaterial.hpp"
#include "AMaterial.hpp"

Plugin::SimpleMaterial::SimpleMaterial(const Component::Color &baseColor, float diffuseFactor)
        : Raytracer::AMaterial("SimpleMaterial"), _baseColor(baseColor), _diffuseFactor(diffuseFactor) {}

Component::Color Plugin::SimpleMaterial::computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                      const Component::Vector3f &lightDirection, float lightIntensity) const {
    float cosTheta = std::max(0.0f, normal.dot(lightDirection));
    Component::Color color = _baseColor * (_diffuseFactor * cosTheta);
    return color;
}

Component::Color Plugin::SimpleMaterial::getDiffuse() const {
    return _baseColor;
}

float Plugin::SimpleMaterial::getSpecular() const {
    return 0.0f;
}

float Plugin::SimpleMaterial::getShininess() const {
    return 1.0f;
}

Raytracer::IMaterial *createMaterial(const libconfig::Setting &setting) {
    Component::Color baseColor(setting["baseColor"][0], setting["baseColor"][1], setting["baseColor"][2]);
    float diffuseFactor = setting["diffuseFactor"];
    return new Plugin::SimpleMaterial(baseColor, diffuseFactor);
}

const char *getName() {
    return "SimpleMaterial";
}

Raytracer::CompType getType() {
    return Raytracer::CompType::MATERIAL;
}
