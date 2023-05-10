/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AEntity
*/

#include <iostream>
#include "AEntity.hpp"

Raytracer::AEntity::AEntity(Raytracer::CompType type, const Component::Vector3f &position, const Component::Vector3f &rotation) : _type(type), _position(position), _rotation(rotation), _scale({1.0f, 1.0f, 1.0f})
{
}

void Raytracer::AEntity::translate(const Component::Vector3f &newPos)
{
    _position = _position + newPos;
}

void Raytracer::AEntity::rotate(const Component::Vector3f &newRot)
{
    _rotation = _rotation + newRot;
}

void Raytracer::AEntity::scale(const Component::Vector3f &newScale)
{
    _scale = _scale * newScale;
}

Component::Vector3f Raytracer::AEntity::getPosition() const
{
    return _position;
}

Component::Vector3f Raytracer::AEntity::getRotation() const
{
    return _rotation;
}

Raytracer::CompType Raytracer::AEntity::getType() const
{
    return _type;
}
