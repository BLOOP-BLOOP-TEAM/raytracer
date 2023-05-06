/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Plugin
*/

#include "Plugin.hpp"

Raytracer::Plugin::Plugin(const std::string& filepath)
{
    _handle = dlopen(filepath.c_str(), RTLD_NOW);
    if (!_handle) {
        throw std::runtime_error("Failed to load plugin: " + filepath + "\nError: " + std::string(dlerror()));
    }
}

Raytracer::Plugin::~Plugin()
{
    if (_handle) {
        dlclose(_handle);
    }
}
