/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ACam
*/

#include "ACam.hpp"

Raytracer::ACam::ACam(const std::string &type, const Component::Vector3f &position) : AEntity("Cam", position), _typeCam(type)
{
}
