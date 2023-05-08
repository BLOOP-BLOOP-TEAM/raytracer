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
    /**
     * @brief The Text struct
     * 
     * This struct represents text to be displayed on the screen.
     */
    struct Text {
        std::string id;
        std::string fontPath = FONT;
        std::string text = " ";
        int size = 15;
        Component::Vector3f pos = Component::Vector3f();
        Component::Color textColor = Component::Color();
        Component::Color backgroundColor = Component::Color();

        /**
         * @brief Constructor for Text struct
         * 
         * @param id The unique ID of the text component
         */
        Text(std::string id);

        /**
         * @brief Constructor for Text struct
         * 
         * @param id The unique ID of the text component
         * @param fontPath The path to the font file
         * @param text The text to display
         * @param size The font size
         * @param pos The position of the text
         * @param textColor The color of the text
         * @param backgroundColor The background color of the text
         */
        Text(std::string id, std::string fontPath, std::string text, int size, Component::Vector3f pos,
            Component::Color textColor, Component::Color backgroundColor);
    };
}