/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Image
*/

#include "Image.hpp"

Raytracer::Image::Image(int width, int height)
        : width(width), height(height), pixels(height, std::vector<Component::Color>(width)) {}

void Raytracer::Image::set_pixel(int x, int y, const Component::Color &color) {
    pixels[y][x] = color;
}

Component::Color Raytracer::Image::get_pixel(int x, int y) const {
    return pixels[y][x];
}

void Raytracer::Image::write_ppm(const std::string &filename) const {
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
