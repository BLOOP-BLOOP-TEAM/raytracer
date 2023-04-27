/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** DisplayModule
*/

#include "DisplayModule.hpp"

namespace Raytracer {

    DisplayModule::DisplayModule(unsigned int width, unsigned int height, const std::string& title)
            : width(width), height(height), window(sf::VideoMode(width, height), title), pixels(sf::Points, width * height) {
    }

    DisplayModule::~DisplayModule() {
    }

    void DisplayModule::update(const Image &image) {
        // Mettre à jour les pixels
        for (unsigned int y = 0; y < height; ++y) {
            for (unsigned int x = 0; x < width; ++x) {
                Component::Color color = image.get_pixel(x, y);
                size_t index = y * width + x;
                pixels[index].position = sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
                pixels[index].color = sf::Color(color.r, color.g, color.b);
            }
        }

        // Dessiner et afficher les pixels
        window.clear();
        window.draw(pixels);
        window.display();

        // Gérer les événements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    bool DisplayModule::isOpen() const {
        return window.isOpen();
    }

}
