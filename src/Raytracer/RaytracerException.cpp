/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** RaytracerException
*/

#include "RaytracerException.hpp"

Raytracer::RaytracerException::RaytracerException(const std::string &mess)
    : _message(mess)
{
}

const char *Raytracer::RaytracerException::what() const noexcept
{
    return (_message.c_str());
}
