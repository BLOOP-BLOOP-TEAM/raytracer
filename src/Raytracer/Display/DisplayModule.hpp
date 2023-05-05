/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** DisplayModule
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Image.hpp"
#include "Text.hpp"

namespace Raytracer {
    class DisplayModule {
        public:
            DisplayModule(unsigned int width, unsigned int height, const std::string& title);

            ~DisplayModule();

            void update(const Image &image);

            bool isOpen() const;

            void displayPixels(const Image &image);

            void displayGuy();

            void initGuy();

            void setText(const Component::Text &textComponent);

            void updateText(sf::Text &sfText, const Component::Text &textComponent);

            sf::RenderWindow &getWindow();

        protected:
        private:
            unsigned int _width;
            unsigned int _height;
            sf::RenderWindow _window;
            sf::VertexArray _pixels;
            std::map<std::string, sf::Text> _allSfTexts;
            std::map<std::string, sf::Font> _allFonts;
            std::vector<Component::Text> _allTexts;
    };
}
