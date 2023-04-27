/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Scene
*/

#include "Scene.hpp"
#include "Image.hpp"

Raytracer::Scene::Scene() : _image(std::make_unique<Image>(1920, 1080))
{
}

void Raytracer::Scene::calculateImage()
{
    _image->calculateImage(_entities);
}
