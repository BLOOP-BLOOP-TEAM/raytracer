/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder
*/

#include <iostream>
#include <libconfig.h++>
#include <vector>
#include "Api.hpp"
#include "Cylinder.hpp"

static const std::string cylinderName = "Cylinder";

Plugin::Cylinder::Cylinder(const Component::Vector3f &position, const Component::Vector3f &rotation, double radius, double height,
                            Component::Vector3f &basePoint, Component::Vector3f &topPoint)
    : APrimitive("Cylinder", position, rotation), _radius(radius), _height(height)
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

double Plugin::Cylinder::intersect(const Raytracer::Ray &ray) const
{
    Component::Vector3f d = ray.direction;
    Component::Vector3f o = ray.origin - getPosition();
    Component::Vector3f axis = _axis;
    double h = _height;
    double r = _radius;

    double a = d.dot(d) - pow(d.dot(axis), 2);
    double b = 2 * (d.dot(o) - d.dot(axis) * o.dot(axis));
    double c = o.dot(o) - pow(o.dot(axis), 2) - r * r;

    double delta = b * b - 4 * a * c;

    std::vector<double> intersections;

    if (delta >= 0) {
        double t1 = (-b - sqrt(delta)) / (2 * a);
        double t2 = (-b + sqrt(delta)) / (2 * a);

        double minT = std::min(t1, t2);
        double maxT = std::max(t1, t2);

        for (double t : {minT, maxT}) {
            Component::Vector3f intersect = ray.origin + ray.direction * t;
            double height = (intersect - getPosition()).dot(_axis);

            if (height >= 0 && height <= _height) {
                intersections.push_back(t);
            }
        }
    }

    for (double faceHeight : {0.0, _height}) {
        double t = (faceHeight - o.dot(axis)) / d.dot(axis);

        if (t > 0) {
            Component::Vector3f intersect = ray.origin + ray.direction * t;
            Component::Vector3f projected = intersect - getPosition() - axis * faceHeight;
            
            if (projected.dot(projected) <= r * r) {
                intersections.push_back(t);
            }
        }
    }

    if (!intersections.empty()) {
        return *std::min_element(intersections.begin(), intersections.end());
    }

    return -1;
}

Component::Vector3f Plugin::Cylinder::getNormal(const Component::Vector3f &hitPoint) const
{
    return (hitPoint - getPosition()).normalize();
}

Raytracer::IEntity *createEntity(const libconfig::Setting &setting)
{
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    Component::Vector3f rotation(setting["rotation"][0], setting["rotation"][1], setting["rotation"][2]);
    Component::Vector3f basePoint(setting["basePoint"][0], setting["basePoint"][1], setting["basePoint"][2]);
    Component::Vector3f topPoint(setting["topPoint"][0], setting["topPoint"][1], setting["topPoint"][2]);
    double height = 0;
    double radius = 0;

    setting.lookupValue("radius", radius);
    setting.lookupValue("height", height);
    return new Plugin::Cylinder(position, rotation, radius, height, basePoint, topPoint);
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