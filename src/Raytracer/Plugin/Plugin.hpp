/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Plugin
*/

#pragma once

#include <string>
#include <dlfcn.h>
#include <iostream>
#include "Plugin.hpp"

namespace Raytracer {
    class Plugin {
    public:
        explicit Plugin(const std::string &filepath);

        ~Plugin();

        template<typename Func>
        Func getFunction(const std::string& funcName) const {
            void* funcPtr = dlsym(_handle, funcName.c_str());
            if (!funcPtr) {
                throw std::runtime_error("Failed to load function: " + funcName + "\nError: " + std::string(dlerror()));
            }
            return reinterpret_cast<Func>(funcPtr);
        }

    private:
        void *_handle;
    };
}
