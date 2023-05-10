/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Image
*/

#include "CompType.hpp"
#include "Image.hpp"
#include "Calculator.hpp"

Raytracer::Image::Image(int width, int height)
        : width(width), height(height), pixels(height, std::vector<Component::Color>(width)) {}

Component::Color Raytracer::Image::getPixel(unsigned int x, unsigned int y) const
{
    if (x >= width || y >= height)
        throw std::runtime_error("Pixel out of range");
    return pixels[y][x];
}

void Raytracer::Image::writePPM(const std::string &filename) const
{
    std::ofstream file(filename);

    file << "P3\n";
    file << width << " " << height << "\n";
    file << MAX_COLOR << "\n";

    for (const auto &row : pixels) {
        for (const auto &pixel : row) {
            file << pixel.r << " " << pixel.g << " " << pixel.b << " ";
        }
        file << "\n";
    }

    file.close();
}

void Raytracer::Image::calculateImage(std::vector<IEntity *> &entities, Raytracer::ISkybox *skybox)
{
    std::cout << "Image calculated" << std::endl;
    Calculator calculator(width, height, entities, pixels, skybox);
    try {
        calculator.calculatePixels();
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
