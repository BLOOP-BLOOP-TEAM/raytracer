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
    /**
     * @brief The Plugin class provides a way to load dynamic libraries and retrieve functions from them.
     */
    class Plugin {
        public:
            /**
             * @brief Constructor for Plugin class.
             * 
             * @param filepath The path to the dynamic library to load.
             */
            explicit Plugin(const std::string &filepath);

            ~Plugin();

            /**
             * @brief Retrieves a function from the loaded dynamic library.
             * 
             * @tparam Func The type of the function to retrieve.
             * @param funcName The name of the function to retrieve.
             */
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