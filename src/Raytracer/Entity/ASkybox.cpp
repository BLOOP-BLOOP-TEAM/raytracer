/*
** EPITECH PROJECT, 2023
** Project
** File description:
** ASkybox
*/

#include "ASkybox.hpp"

Raytracer::ASkybox::ASkybox(const std::string &type) : _type(type), _isLoaded(false)
{
}

std::string Raytracer::ASkybox::getType() const
{
    return _type;
}

bool Raytracer::ASkybox::isLoaded()
{
    return _isLoaded;
}
