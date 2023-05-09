/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Image
*/

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
#include "Color.hpp"
#include "IEntity.hpp"
#include "ALight.hpp"
#include "ACam.hpp"

namespace Raytracer {

    /**
     * @brief The Image class
     * 
     * This class represents an image and provides methods for manipulating it.
     */
    class Image {
        public:
            /**
             * @brief Constructor for Image class
             * 
             * @param width The width of the image
             * @param height The height of the image
             */
            Image(int width, int height);

            /**
             * @brief Getter function for pixel color
             * 
             * @param x The x-coordinate of the pixel
             * @param y The y-coordinate of the pixel
             */
            [[nodiscard]] Component::Color getPixel(unsigned int x, unsigned int y) const;

            /**
             * @brief Writes the image as a PPM file
             * 
             * @param filename The name of the file to be written
             */
            void writePPM(const std::string &filename) const;

            /**
             * @brief Calculates the color of each pixel in the image
             * 
             * @param entities A vector of IEntity objects used to calculate the color of each pixel
             */
            void calculateImage(std::vector<IEntity *> &entities);
        private:
            int width;
            int height;
            static const int MAX_COLOR = 255;
            std::vector<std::vector<Component::Color>> pixels;
    };
}
