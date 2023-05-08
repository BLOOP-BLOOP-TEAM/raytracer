/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane
*/

#include <libconfig.h++>
#include "Api.hpp"
#include "Plane.hpp"

static const std::string PLANE = "Plane";

Plugin::Plane::Plane(const Component::Vector3f &position, const Component::Vector3f &normal)
        : APrimitive(PLANE, position), _normal(normal.normalize()) {}

double Plugin::Plane::intersect(const Raytracer::Ray &ray) const
{
    double denom = _normal.dot(ray.direction);

    if (std::abs(denom) < 1e-6) {
        return -1.0f;
    }
    double t = (_position - ray.origin).dot(_normal) / denom;
    return t >= 0 ? t : -1.0f;
}

Component::Vector3f Plugin::Plane::getNormal(const Component::Vector3f &hitPoint) const
{
    return _normal;
}

Raytracer::IEntity *createEntity(const libconfig::Setting &setting)
{
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    Component::Vector3f normal(setting["normal"][0], setting["normal"][1], setting["normal"][2]);
    return new Plugin::Plane(position, normal);
}

void destroyEntity(Raytracer::IEntity *entity)
{
    delete entity;
}

const char *getName()
{
    return PLANE.c_str();
}

LibType getType()
{
    return LibType::ENTITY;
}
