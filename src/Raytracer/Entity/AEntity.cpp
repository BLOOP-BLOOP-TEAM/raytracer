/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AEntity
*/

#include "AEntity.hpp"

Raytracer::AEntity::AEntity(Raytracer::CompType type, const Component::Vector3f &position) : _type(type), _position(position)
{
}

void Raytracer::AEntity::translate(const Component::Vector3f &newPos)
{

}

void Raytracer::AEntity::rotate(const Component::Vector3f &newRot)
{

}

void Raytracer::AEntity::scale(const Component::Vector3f &newScale)
{

}

Component::Vector3f Raytracer::AEntity::getPosition() const
{
    return (this->_position);
}

Raytracer::CompType Raytracer::AEntity::getType() const
{
    return _type;
}
