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
    /**
     * @brief The DisplayModule class
     * 
     * This class is responsible for displaying the rendered image on screen
     */
    class DisplayModule {
        public:
            /**
             * @brief Construct a new Display Module object
             * 
             * @param width Width of the window
             * @param height Height of the window
             * @param title Title of the window
             * @param scenesManager ScenesManager object to handle scenes
             */
            DisplayModule(unsigned int width, unsigned int height, const std::string& title, ScenesManager &scenesManager);

            ~DisplayModule();

            /**
             * @brief Update the content of the window with an image
             * 
             * @param image The image to display
             */
            void update(const Image &image);

            /**
             * @brief Check if the window is open
             */
            bool isOpen() const;

            /**
             * @brief Get the window object
             */
            sf::RenderWindow &getWindow();

            /**
             * @brief Display the pixels of an image in the window
             * 
             * @param image The image to display
             */
            void displayPixels(const Image &image);

            /**
             * @brief Display all the texts loaded
             */
            void displayGuy();

            /**
             * @brief Initialize texts informations
             */
            void initGuy();

            /**
             * @brief Set text to be displayed in the window
             * 
             * @param textComponent A text component containing the text to display
             */
            void setText(const Component::Text &textComponent);

            /**
             * @brief Update text in the window
             * 
             * @param sfText A reference to the sf::Text object to update
             * @param textComponent The updated text component
             */
            void updateText(sf::Text &sfText, const Component::Text &textComponent);

            /**
             * @brief Update the camera position and rotation values in the window
             */
            void updateCameraValues();

            /**
             * @brief Get the camera position
             */
            std::string getCameraPos();

            /**
             * @brief Get the camera rotation 
             */
            std::string getCameraRotation();

            /**
             * @brief Convert a Vector3f object to a string
             * 
             * @param vec The Vector3f object to convert
             */
            std::string Vector3fToString(Component::Vector3f vec);

            [[nodiscard]] std::string GetSceneName(const std::string &filename);

        protected:
        private:
            unsigned int _width;
            unsigned int _height;
            sf::RenderWindow _window;
            sf::VertexArray _pixels;
            ScenesManager &_scenesManager;
            std::map<std::string, sf::Text> _allSfTexts;
            std::map<std::string, sf::Font> _allFonts;
            std::vector<Component::Text> _allTexts;
    };
};