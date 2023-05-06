/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ACam
*/

#include "ACam.hpp"

Raytracer::ACam::ACam(const std::string &typeCam, const Component::Vector3f &position, const Component::Vector3f &rotation,
            float field_of_view) : AEntity(Raytracer::CompType::CAM, position), _typeCam(typeCam), _rotation(rotation),
                                                        _fieldOfView(field_of_view), _isEdited(false) {}
float Raytracer::ACam::getFieldOfView() const {
    return _fieldOfView;
}

const Component::Vector3f &Raytracer::ACam::getRotation() const {
    return _rotation;
}

void Raytracer::ACam::setRotation(const Component::Vector3f &rotation) {
    _rotation = rotation;
}

const std::string &Raytracer::ACam::getTypeCam() const {
    return _typeCam;
}

const bool Raytracer::ACam::isEdited() const {
    return _isEdited;
}

void Raytracer::ACam::setEdit(bool status) {
    _isEdited = status;
}
