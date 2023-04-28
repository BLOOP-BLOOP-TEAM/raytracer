/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LoadConfig
*/

#pragma once

#include <string>

namespace Raytracer {
    class LoadConfig {
        public:
            LoadConfig() = default;
            ~LoadConfig() = default;

            int loadConfigFile(const std::string &path);

        protected:
        private:
    };
}; // namespace Raytracer
