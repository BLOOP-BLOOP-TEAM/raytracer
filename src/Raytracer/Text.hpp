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

namespace Component {
    struct Text {
        std::string id;
        std::string fontPath = "arial.ttf";
        std::string text = " ";
        int size = 20;
        Component::Color backgroundColor = Component::Color();
        Component::Color textColor = Component::Color();
        Component::Vector3f pos = Component::Vector3f();

        Text(std::string id);
        Text(std::string id, std::string fontPath, std::string text, int size, Component::Vector3f pos,
            Component::Color textColor, Component::Color backgroundColor);
    };
};
