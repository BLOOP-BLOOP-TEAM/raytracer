/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SimpleMaterialApi
*/

#include "SimpleMaterial.hpp"
#include "SimpleMaterialApi.hpp"

Raytracer::IMaterial *Plugin::SimpleMaterialApi::createMaterial(const libconfig::Setting &setting) {
    Component::Color baseColor(setting["baseColor"][0], setting["baseColor"][1], setting["baseColor"][2]);
    float diffuseFactor = setting["diffuseFactor"];
    return new Plugin::SimpleMaterial(baseColor, diffuseFactor);
}

const char *Plugin::SimpleMaterialApi::getName() const {
    return "SimpleMaterial";
}

Raytracer::CompType Plugin::SimpleMaterialApi::getType() const {
    return Raytracer::CompType::MATERIAL;
}
