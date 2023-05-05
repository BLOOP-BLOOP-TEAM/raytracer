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
        initGuy();
    }

    DisplayModule::~DisplayModule() {}

    void DisplayModule::initGuy() {
        Component::Text CameraPosTitle("#cameraPosTitle", "arial.ttf", "Camera Position :", 20, {0, 0, 0}, {255, 255, 0}, {0, 0, 0});

        _allTexts.push_back(CameraPosTitle);
    }

    void DisplayModule::setText(const Component::Text &textComponent) {
        auto fontIt = _allFonts.find(textComponent.fontPath);
        if (fontIt == _allFonts.end()) {
            sf::Font font;
            if (!font.loadFromFile(textComponent.fontPath))
                // throw(std::invalid_argument("Impossible de charger la font"));
            _allFonts.insert({textComponent.fontPath, font});
            fontIt = _allFonts.find(textComponent.fontPath);
        }

        sf::Text text;

        text.setFont(fontIt->second);
        text.setString(textComponent.text);
        text.setPosition({textComponent.pos.x, textComponent.pos.y});
        text.setFillColor(sf::Color(textComponent.textColor.r,
            textComponent.textColor.g,
            textComponent.textColor.b,
            255));
        text.setCharacterSize(textComponent.size);
        std::cout << textComponent.id << std::endl;
        _allSfTexts.insert({  textComponent.id, text });
        _window.draw(text);
    }

    void DisplayModule::updateText(sf::Text &sfText, const Component::Text &textComponent) {
        sfText.setString(textComponent.text);
        sfText.setPosition({textComponent.pos.x, textComponent.pos.y});
        sfText.setFillColor(sf::Color(textComponent.textColor.r,
            textComponent.textColor.g,
            textComponent.textColor.b,
            255));
        _window.draw(sfText);
    }

    void DisplayModule::displayPixels(const Image &image) {
        // Mettre à jour les pixels
        for (unsigned int y = 0; y < _height; ++y) {
            for (unsigned int x = 0; x < _width; ++x) {
                Component::Color color = image.get_pixel(x, y);
                size_t index = y * _width + x;
                _pixels[index].position = sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
                _pixels[index].color = sf::Color(color.r, color.g, color.b);
            }
        }
    }

    void DisplayModule::displayGuy() {
        for (const auto &text : _allTexts) { // gestion des textes
            auto it = _allSfTexts.find(text.id);
            if (it == _allSfTexts.end())
                setText(text);
            else
                updateText(it->second, text);
        }
    }

    void DisplayModule::update(const Image &image) {
        // Dessiner et afficher les pixels
        displayPixels(image);
        displayGuy();
        _window.clear();
        _window.draw(_pixels);
        _window.display();
    }

    bool DisplayModule::isOpen() const {
        return _window.isOpen();
    }

    sf::RenderWindow &DisplayModule::getWindow() {
        return _window;
    }
}
