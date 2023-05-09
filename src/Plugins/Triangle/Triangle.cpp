/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Triangle
*/

#include <iostream>
#include <libconfig.h++>
#include "Api.hpp"
#include "Triangle.hpp"

static const std::string triangleName = "Triangle";

namespace Plugin {
    Triangle::Triangle(Component::Matrix3x3 &matrix, Component::Vector3f &position)
        : APrimitive(triangleName, position), _matrix(matrix)
    {
    }

    double Triangle::intersect(const Raytracer::Ray &ray) const
    {
        const float epsilon = 0.0000001;
        Component::Vector3f edge1 = {_matrix.m[3] - _matrix.m[0], _matrix.m[4] - _matrix.m[1], _matrix.m[5] - _matrix.m[2]};
        Component::Vector3f edge2 = {_matrix.m[6] - _matrix.m[0], _matrix.m[7] - _matrix.m[1], _matrix.m[8] - _matrix.m[2]};
        Component::Vector3f h = ray.direction.cross(edge2);
        double a = edge1.dot(h);

        if (a > -epsilon && a < epsilon) {
            return false;
        }

        Component::Vector3f vector = {_matrix.m[0], _matrix.m[1], _matrix.m[2]};
        double f = 1.0 / a;
        Component::Vector3f s = ray.origin - vector;
        double u = f * s.dot(h);

        if (u < 0.0 || u > 1.0) {
            return false;
        }

        Component::Vector3f q = s.cross(edge1);
        double v = f * ray.direction.dot(q);

        if (v < 0.0 || u + v > 1.0) {
            return false;
        }
        
        double t = f * edge2.dot(q);

        if (t > epsilon) {
            return t;
        }
        return (true);
    }

    Component::Vector3f Triangle::getNormal(const Component::Vector3f &hitPoint) const
    {
        Component::Vector3f edge1 = {_matrix.m[3] - _matrix.m[0], _matrix.m[4] - _matrix.m[1], _matrix.m[5] - _matrix.m[2]};
        Component::Vector3f edge2 = {_matrix.m[6] - _matrix.m[0], _matrix.m[7] - _matrix.m[1], _matrix.m[8] - _matrix.m[2]};
        Component::Vector3f normal = edge1.cross(edge2);
        return normal.normalize();
    }
}

Raytracer::IEntity *createEntity(const libconfig::Setting &setting)
{
    Component::Matrix3x3 matrix(setting["matrix"][0], setting["matrix"][1], setting["matrix"][2],
                                setting["matrix"][3], setting["matrix"][4], setting["matrix"][5],
                                setting["matrix"][6], setting["matrix"][7], setting["matrix"][8]);

    Component::Vector3f position(setting["position"][0], setting["position"][1], setting["position"][2]);
    return new Plugin::Triangle(matrix, position);
}

const char *getName()
{
    return triangleName.c_str();
}

LibType getType()
{
    return LibType::ENTITY;
}

void destroyEntity(Raytracer::IEntity *entity)
{
    std::cout << "destroy triangle" << std::endl;
    delete entity;
}
