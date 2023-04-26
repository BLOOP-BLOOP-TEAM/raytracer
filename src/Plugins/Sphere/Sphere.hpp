/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere
*/

#pragma once

#include "Vector3f.hpp"

class Sphere {
    public:
        Sphere();
        ~Sphere();
        //bool intersect (rayon)

    protected:
    private:
        Vector3f _position;
        float _radius;

};
