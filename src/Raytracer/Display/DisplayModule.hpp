/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** DisplayModule
*/

#pragma once

#include "Image.hpp"
#include <SFML/Graphics.hpp>
#include "Image.hpp"

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
             */
            DisplayModule(unsigned int width, unsigned int height, const std::string& title);

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

        protected:
        private:
            unsigned int _width;
            unsigned int _height;
            sf::RenderWindow _window;
            sf::VertexArray _pixels;
    };
};