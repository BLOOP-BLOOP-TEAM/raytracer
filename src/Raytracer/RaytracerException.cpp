/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** RaytracerException
*/

#include "RaytracerException.hpp"

namespace Raytracer {
    RaytracerException::RaytracerException(const std::string &message) : _message(message) {}

    const std::string &RaytracerException::message() const noexcept {
        return _message;
    }

    const char *RaytracerException::what() const noexcept {
        return _message.c_str();
    }
}
