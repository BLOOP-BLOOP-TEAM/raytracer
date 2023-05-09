/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** DisplayModule
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include "Image.hpp"
#include "Text.hpp"
#include "Color.hpp"
#include "ScenesManager.hpp"
#include "RaytracerException.hpp"

namespace Raytracer {
    class DisplayModule {
        public:
            DisplayModule(unsigned int width, unsigned int height, const std::string& title, ScenesManager &scenesManager);

            ~DisplayModule();

            void update(const Image &image);

            bool isOpen() const;

            void displayPixels(const Image &image);

            void displayGuy();

            void initGuy();

            void setText(const Component::Text &textComponent);

            void updateText(sf::Text &sfText, const Component::Text &textComponent);

            void updateCameraValues();

            sf::RenderWindow &getWindow();

            std::string getCameraPos();

            std::string getCameraRotation();

            std::string PosVector3fToString(Component::Vector3f vec);

            std::string Vector3fToString(Component::Vector3f vec);

            [[nodiscard]] std::string GetSceneName(const std::string &filename);

        protected:
        private:
            unsigned int _width;
            unsigned int _height;
            ScenesManager &_scenesManager;
            sf::RenderWindow _window;
            sf::VertexArray _pixels;
            std::map<std::string, sf::Text> _allSfTexts;
            std::map<std::string, sf::Font> _allFonts;
            std::vector<Component::Text> _allTexts;
    };
}
