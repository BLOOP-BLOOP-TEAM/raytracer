/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** DisplayModule
*/

#include "DisplayModule.hpp"

namespace Raytracer {

    DisplayModule::DisplayModule(unsigned int width, unsigned int height, const std::string& title)
            : _width(width), _height(height), _window(sf::VideoMode(width, height), title), _pixels(sf::Points, width * height) {
    }

    DisplayModule::~DisplayModule() {}

    void DisplayModule::update(const Image &image)
    {
        // Mettre à jour les pixels
        for (unsigned int y = 0; y < _height; ++y) {
            for (unsigned int x = 0; x < _width; ++x) {
                Component::Color color = image.get_pixel(x, y);
                size_t index = y * _width + x;
                _pixels[index].position = sf::Vector2f(static_cast<double>(x), static_cast<double>(y));
                _pixels[index].color = sf::Color(color.r, color.g, color.b);
            }
        }

        // Dessiner et afficher les pixels
        _window.clear();
        _window.draw(_pixels);
        _window.display();
    }

    bool DisplayModule::isOpen() const
    {
        return _window.isOpen();
    }

    sf::RenderWindow &DisplayModule::getWindow()
    {
        return _window;
    }
}
