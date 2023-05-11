/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Text
*/

#pragma once

#include "Vector3f.hpp"
#include "Color.hpp"
#include "string"

static const std::string FONT = "./assets/fonts/arial.ttf";

namespace Component {
    struct Text {
        std::string id;
        std::string fontPath = FONT;
        std::string text = " ";
        int size = 15;
        Component::Vector3f pos = Component::Vector3f();
        Component::Color textColor = Component::Color();
        Component::Color backgroundColor = Component::Color();

        explicit Text(std::string id);
        Text(std::string id, std::string fontPath, std::string text, int size, Component::Vector3f pos,
            Component::Color textColor, Component::Color backgroundColor);
    };
};
