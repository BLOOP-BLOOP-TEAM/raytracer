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
class DisplayModule {
    public:
        DisplayModule(unsigned int width, unsigned int height, const std::string& title);

        ~DisplayModule();

        void update(const Image &image);

        bool isOpen() const;

        sf::RenderWindow &getWindow();

    protected:
    private:
        unsigned int _width;
        unsigned int _height;
        sf::RenderWindow _window;
        sf::VertexArray _pixels;
    };
}
