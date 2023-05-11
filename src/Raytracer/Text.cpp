/*
** EPITECH PROJECT, 2023
** raytracer [WSL: Ubuntu-20.04]
** File description:
** Text
*/

#include "Text.hpp"

Component::Text::Text(std::string id): id(id) {}

Component::Text::Text(std::string id, std::string fontPath, std::string text, int size, Component::Vector3f pos,
            Component::Color textColor, Component::Color backgroundColor)
            : id(std::move(id)), fontPath(std::move(fontPath)), text(std::move(text)), size(size), pos(pos), textColor(textColor), backgroundColor() {}
