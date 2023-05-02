/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

Plugin::Sphere::Sphere(const Component::Vector3f &position, float radius) : APrimitive("Sphere", position), _radius(radius)
{

}

float Plugin::Sphere::intersect(const Raytracer::Ray &ray) const
{
    Component::Vector3f L = ray.origin - this->getPosition();
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

Component::Vector3f Plugin::Sphere::getNormal(const Component::Vector3f &hit_point) const {
    return (hit_point - this->getPosition()).normalize();
}
