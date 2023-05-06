/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** DisplayModule
*/

#include "DisplayModule.hpp"

static const std::string ID_CAMERA_POS_TITLE = "#cameraPosTitle";
static const std::string ID_CAMERA_POS_VALUE = "#cameraPosValue";
static const std::string ID_CAMERA_ROTATION_TITLE = "#cameraRotationTitle";
static const std::string ID_CAMERA_ROTATION_VALUE = "#cameraRotationValue";

namespace Raytracer {

    DisplayModule::DisplayModule(unsigned int width, unsigned int height, const std::string& title, ScenesManager &scenesManager)
            : _width(width), _height(height), _window(sf::VideoMode(width, height), title), _scenesManager(scenesManager), _pixels(sf::Points, width * height) {}

    DisplayModule::~DisplayModule() {}

    std::string DisplayModule::Vector3fToString(Component::Vector3f vec) {
        std::stringstream ss;

        ss << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return ss.str();
    }

    std::string DisplayModule::getCameraPos() {
        for (const auto &entity: _scenesManager.getSceneActual().getEntities()) {
            if (entity->getType() == CompType::CAM)
                return Vector3fToString(entity->getPosition());
        }
        return "UNDEFINED";
    }

    std::string DisplayModule::getCameraRotation() {
        const std::vector<Raytracer::IEntity *> &entities = _scenesManager.getSceneActual().getEntities();

        for (const auto &entity: entities) {
            if (entity->getType() == CompType::CAM) {
                ACam *cam = static_cast<ACam *>(entity);
                return Vector3fToString(cam->getRotation());
            }
        }
        return "UNDEFINED";
    }

    void DisplayModule::initGuy() {
        Component::Text CameraPosTitle(ID_CAMERA_POS_TITLE, FONT, "Camera Position :", 15, {10, 10, 0}, {255, 0, 0}, {0, 0, 0});
        Component::Text CameraPosValue(ID_CAMERA_POS_VALUE, FONT, getCameraPos(), 15, {150, 10, 0}, {255, 0, 0}, {0, 0, 0});

        Component::Text CameraRotationTitle(ID_CAMERA_ROTATION_TITLE, FONT, "Camera Rotation :", 15, {10, 30, 0}, {255, 0, 0}, {0, 0, 0});
        Component::Text CameraRotationValue(ID_CAMERA_ROTATION_VALUE, FONT, getCameraRotation(), 15, {150, 30, 0}, {255, 0, 0}, {0, 0, 0});

        _allTexts.push_back(CameraPosTitle);
        _allTexts.push_back(CameraPosValue);
        _allTexts.push_back(CameraRotationTitle);
        _allTexts.push_back(CameraRotationValue);
    }

    void DisplayModule::setText(const Component::Text &textComponent) {
        auto fontIt = _allFonts.find(textComponent.fontPath);
        if (fontIt == _allFonts.end()) {
            sf::Font font;
            if (!font.loadFromFile(textComponent.fontPath))
                throw(std::invalid_argument("Impossible de charger la font")); // a modifier
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

    void DisplayModule::updateCameraValues() {
        for (auto &text :_allTexts) {
            if (text.id == ID_CAMERA_POS_VALUE)
                text.text = getCameraPos();
        }
    }

    void DisplayModule::update(const Image &image) {
        // Dessiner et afficher les pixels
        _window.clear();
        displayPixels(image);
        _window.draw(_pixels);
        updateCameraValues();
        displayGuy();
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
