/*
** EPITECH PROJECT, 2023
** Project
** File description:
** ASkybox
*/

#pragma once

#include "ISkybox.hpp"

namespace Raytracer {
    class ASkybox : public ISkybox {
        public:
            explicit ASkybox(const std::string &type);

            ~ASkybox() override = default;

            [[nodiscard]] std::string getType() const override;

            [[nodiscard]] bool isLoaded() override;

            [[nodiscard]] Component::Color getColorFromRay(const Component::Vector3f &direction) override = 0;

        protected:
            bool _isLoaded;
        private:
            std::string _type;
    };
}
