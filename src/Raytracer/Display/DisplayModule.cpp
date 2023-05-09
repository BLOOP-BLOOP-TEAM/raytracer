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
static const std::string ID_SCENE_TITLE = "#sceneTitle";
static const std::string ID_SCENE_VALUE = "#sceneValue";
static const std::string UNDEFINED = "UNDEFINED";

namespace Raytracer {

    DisplayModule::DisplayModule(unsigned int width, unsigned int height, const std::string& title, ScenesManager &scenesManager)
            : _width(width), _height(height), _window(sf::VideoMode(width, height), title), _scenesManager(scenesManager), _pixels(sf::Points, width * height) {}

    DisplayModule::~DisplayModule() {}

    std::string DisplayModule::PosVector3fToString(Component::Vector3f vec) {
        std::stringstream ss;

        ss << "(" << vec.z << ", " << vec.y << ", " << vec.x << ")"; // technique de la loutre
        return ss.str();
    }

    std::string DisplayModule::Vector3fToString(Component::Vector3f vec) {
        std::stringstream ss;

        ss << "(" << vec.y << ", " << vec.x << ", " << vec.z << ")";
        return ss.str();
    }

    std::string DisplayModule::getCameraPos() {
        for (const auto &entity: _scenesManager.getSceneActual().getEntities()) {
            if (entity->getType() == CompType::CAM)
                return PosVector3fToString(entity->getPosition());
        }
        return UNDEFINED;
    }

    std::string DisplayModule::getCameraRotation() {
        const std::vector<Raytracer::IEntity *> &entities = _scenesManager.getSceneActual().getEntities();

        for (const auto &entity: entities) {
            if (entity->getType() == CompType::CAM) {
                ACam *cam = static_cast<ACam *>(entity);
                return Vector3fToString(cam->getRotation());
            }
        }
        return UNDEFINED;
    }

    std::string DisplayModule::GetSceneName(const std::string &filename) {
        const std::string extension = ".cfg";
        const std::string prefix = "Scenes/";
        size_t filename_start = filename.find_last_of("/") + 1;
        size_t filename_end = filename.find_last_of(extension);

        if (filename_end == std::string::npos || filename_end < filename_start)
            filename_end = filename.length();
        else
            filename_end -= extension.length();
        return filename.substr(filename_start, filename_end - filename_start + 1);
    }

    void DisplayModule::initGuy() {
        Component::Text CameraPosTitle(ID_CAMERA_POS_TITLE, FONT, "Camera Position :", 15, {10, 40, 0}, {93, 40, 165}, {0, 0, 0});
        Component::Text CameraPosValue(ID_CAMERA_POS_VALUE, FONT, getCameraPos(), 15, {150, 40, 0}, {255, 0, 0}, {0, 0, 0});

        Component::Text CameraRotationTitle(ID_CAMERA_ROTATION_TITLE, FONT, "Camera Rotation :", 15, {10, 60, 0}, {255, 0, 0}, {0, 0, 0});
        Component::Text CameraRotationValue(ID_CAMERA_ROTATION_VALUE, FONT, getCameraRotation(), 15, {150, 60, 0}, {255, 0, 0}, {0, 0, 0});

        Component::Text SceneTitle(ID_SCENE_TITLE, FONT, "Scene Name :", 15, {10, 10, 0}, {255, 0, 0}, {0, 0, 0});
        Component::Text SceneValue(ID_SCENE_VALUE, FONT, GetSceneName(_scenesManager.getSceneActual().getFileName()), 15, {110, 10, 0}, {255, 0, 0}, {0, 0, 0});

        _allTexts.push_back(CameraPosTitle);
        _allTexts.push_back(CameraPosValue);
        _allTexts.push_back(CameraRotationTitle);
        _allTexts.push_back(CameraRotationValue);
        _allTexts.push_back(SceneTitle);
        _allTexts.push_back(SceneValue);
    }

    void DisplayModule::setText(const Component::Text &textComponent) {
        auto fontIt = _allFonts.find(textComponent.fontPath);
        if (fontIt == _allFonts.end()) {
            sf::Font font;
            if (!font.loadFromFile(textComponent.fontPath))
                throw Raytracer::RaytracerException("Impossible de charger la font");
            _allFonts.insert({textComponent.fontPath, font});
            fontIt = _allFonts.find(textComponent.fontPath);
        }

        sf::Text text;

        text.setFont(fontIt->second);
        text.setString(textComponent.text);
        text.setPosition({static_cast<float>(textComponent.pos.x), static_cast<float>(textComponent.pos.y)});
        text.setFillColor(sf::Color(textComponent.textColor.r,
            textComponent.textColor.g,
            textComponent.textColor.b,
            255));
        text.setCharacterSize(textComponent.size);
        _allSfTexts.insert({  textComponent.id, text });
        _window.draw(text);
    }

    void DisplayModule::updateText(sf::Text &sfText, const Component::Text &textComponent) {
        sf::Color colorHighlight = (sf::Color(93, 40, 165, 255));
        sf::Color colorUnhighlight = (sf::Color(250, 0, 0, 255));

        sfText.setString(textComponent.text);
        sfText.setPosition({static_cast<float>(textComponent.pos.x), static_cast<float>(textComponent.pos.y)});
        if (textComponent.id == ID_CAMERA_POS_TITLE)
            _scenesManager.isCtrlActive() ? sfText.setFillColor(colorUnhighlight) : sfText.setFillColor(colorHighlight);
        else if (textComponent.id == ID_CAMERA_ROTATION_TITLE)
            _scenesManager.isCtrlActive() ? sfText.setFillColor(colorHighlight) : sfText.setFillColor(colorUnhighlight);
        else
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
                Component::Color color = image.getPixel(x, y);
                size_t index = y * _width + x;
                _pixels[index].position = sf::Vector2f(static_cast<double>(x), static_cast<double>(y));
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
            if (text.id == ID_CAMERA_POS_VALUE) {
                text.text = getCameraPos();
                _scenesManager.isCtrlActive() ? text.textColor = text.textColor = Component::Color(255, 0, 0) : text.textColor = Component::Color(93, 40, 165);
            }
            if (text.id == ID_CAMERA_ROTATION_VALUE) {
                text.text = getCameraRotation();
                _scenesManager.isCtrlActive() ? text.textColor = Component::Color(93, 40, 165) : text.textColor = Component::Color(255, 0, 0);
            }
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
