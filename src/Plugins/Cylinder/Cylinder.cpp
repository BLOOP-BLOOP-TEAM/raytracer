/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder
*/

#include <iostream>
#include <libconfig.h++>
#include "Api.hpp"
#include "Cylinder.hpp"

static const std::string cylinderName = "Cylinder";

Plugin::Cylinder::Cylinder(const Component::Vector3f &position, float radius, float height,
                            Component::Vector3f &basePoint, Component::Vector3f &topPoint)
    : APrimitive("Cylinder", position), _radius(radius), _height(height)
{
    _axis = calculateCylinderAxis(basePoint, topPoint);
}

Plugin::Cylinder::~Cylinder()
{
}

Component::Vector3f Plugin::Cylinder::calculateCylinderAxis(const Component::Vector3f &basePoint, const Component::Vector3f &topPoint)
{
    Component::Vector3f axis = topPoint - basePoint;

    axis = axis.normalize();
    return axis;
}

float Plugin::Cylinder::intersect(const Raytracer::Ray &ray) const
{
    Component::Vector3f d = ray.direction;
    Component::Vector3f o = ray.origin - getPosition();
    Component::Vector3f axis = _axis;
    float h = _height;
    float r = _radius;

    float a = d.dot(d) - pow(d.dot(axis), 2);
    float b = 2 * (d.dot(o) - d.dot(axis) * o.dot(axis));
    float c = o.dot(o) - pow(o.dot(axis), 2) - r * r;

    float delta = b * b - 4 * a * c;

    if (delta < 0) {
        return -1;
    }

    float t1 = (-b - sqrt(delta)) / (2 * a);
    float t2 = (-b + sqrt(delta)) / (2 * a);

    float min_t = std::min(t1, t2);
    float max_t = std::max(t1, t2);

    for (float t : {min_t, max_t}) {
        Component::Vector3f intersect = ray.origin + ray.direction * t;
        float height = (intersect - getPosition()).dot(_axis);

        if (height >= 0 && height <= _height) {
            return t;
        }
    }
    return -1;
}

Component::Vector3f Plugin::Cylinder::getNormal(const Component::Vector3f &hit_point) const
{
    return (hit_point - getPosition()).normalize();
}

Raytracer::IEntity *createEntity(const libconfig::Setting &setting)
{
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    Component::Vector3f basePoint(setting["basePoint"][0], setting["basePoint"][1], setting["basePoint"][2]);
    Component::Vector3f topPoint(setting["topPoint"][0], setting["topPoint"][1], setting["topPoint"][2]);
    float height = 0;
    float radius = 0;

    setting.lookupValue("radius", radius);
    setting.lookupValue("height", height);
    return new Plugin::Cylinder(position, radius, height, basePoint, topPoint);
}

const char *getName()
{
    return cylinderName.c_str();
}

LibType getType() {
    return LibType::ENTITY;
}

void destroyEntity(Raytracer::IEntity *entity)
{
    std::cout << "destroy cylinder" << std::endl;
    delete entity;
}