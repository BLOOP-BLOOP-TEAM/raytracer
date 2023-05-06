/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere
*/

#include <iostream>
#include <libconfig.h++>
#include "Api.hpp"
#include "Sphere.hpp"

static const std::string SPHERE = "sphere";

Plugin::Sphere::Sphere(const Component::Vector3f &position, float radius) : APrimitive(SPHERE, position), _radius(radius)
{

}

float Plugin::Sphere::intersect(const Raytracer::Ray &ray) const
{
    Component::Vector3f L = ray.origin - getPosition();
    float a = ray.direction.dot(ray.direction);
    float b = 2 * ray.direction.dot(L);
    float c = L.dot(L) - _radius * _radius;
    float delta = b * b - 4 * a * c;

    if (delta < 0) {
        return -1;
    }

    float t1 = (-b - sqrt(delta)) / (2 * a);
    float t2 = (-b + sqrt(delta)) / (2 * a);

    if (t1 > 0 && t2 > 0) {
        return std::min(t1, t2);
    } else if (t1 > 0) {
        return t1;
    } else if (t2 > 0) {
        return t2;
    } else {
        return -1;
    }
}

Component::Vector3f Plugin::Sphere::getNormal(const Component::Vector3f &hitPoint) const
{
    return (hitPoint - getPosition()).normalize();
}

Raytracer::IEntity *createEntity(const libconfig::Setting &setting)
{
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    float radius = 0;

    setting.lookupValue("radius", radius);
    return new Plugin::Sphere(position, radius);
}

const char *getName()
{
    return SPHERE.c_str();
}

LibType getType()
{
    return LibType::ENTITY;
}

void destroyEntity(Raytracer::IEntity *entity)
{
    std::cout << "destroy sphere" << std::endl;
    delete entity;
}
