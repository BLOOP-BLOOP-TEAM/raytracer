/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane
*/

#include <libconfig.h++>
#include "Plane.hpp"

Plugin::Plane::Plane(const Component::Vector3f &position, const Component::Vector3f &normal)
        : APrimitive("Plane", position), _normal(normal.normalize()) {}

float Plugin::Plane::intersect(const Raytracer::Ray &ray) const {
    float denom = _normal.dot(ray.direction);
    if (std::abs(denom) < 1e-6) {
        return -1.0f;
    }
    float t = (_position - ray.origin).dot(_normal) / denom;
    return t >= 0 ? t : -1.0f;
}

Component::Vector3f Plugin::Plane::getNormal(const Component::Vector3f &hit_point) const {
    return _normal;
}

Component::Color Plugin::Plane::getColor(const Component::Vector3f &hit_point) const {
    int checker_size = 1;
    int x = static_cast<int>(floor(hit_point.x / checker_size));
    int z = static_cast<int>(floor(hit_point.z / checker_size));
    bool is_even = (x + z) % 2 == 0;

    return is_even ? Component::Color(255, 255, 255) : Component::Color(0, 0, 0);
}

Raytracer::IEntity *createEntity(const libconfig::Setting &setting) {
    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    Component::Vector3f normal(setting["normal"][0], setting["normal"][1], setting["normal"][2]);
    return new Plugin::Plane(position, normal);
}

void destroyEntity(Raytracer::IEntity *entity) {
    delete entity;
}

const char *getName() {
    return "Plane";
}

Raytracer::CompType getType() {
    return Raytracer::CompType::PRIMITIVE;
}
