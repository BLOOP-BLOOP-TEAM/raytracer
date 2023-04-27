/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AEntity
*/

#include "AEntity.hpp"

Raytracer::AEntity::AEntity(const std::string &type, const Component::Vector3f &position) : _type(type), _position(position)
{
}
