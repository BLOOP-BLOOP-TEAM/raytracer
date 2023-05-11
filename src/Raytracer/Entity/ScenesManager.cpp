/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ScenesManager
*/

#include "RaytracerException.hpp"
#include "ScenesManager.hpp"
#include "Observer.hpp"
#include "Scene.hpp"

static const std::string keyLeft = "KEY_LEFT_PRESSED";
static const std::string keyRight = "KEY_RIGHT_PRESSED";
static const std::string keyEnter = "KEY_ENTER_PRESSED";
static const std::string keyD = "KEY_D_PRESSED";
static const std::string keyZ = "KEY_Z_PRESSED";
static const std::string keyQ = "KEY_Q_PRESSED";
static const std::string keyS = "KEY_S_PRESSED";
static const std::string keyA = "KEY_A_PRESSED";
static const std::string keyE = "KEY_E_PRESSED";

Raytracer::ScenesManager::ScenesManager() : _sceneActual(0)
{
}

void Raytracer::ScenesManager::addScene(std::unique_ptr<Scene> scene)
{
    _scenes.push_back(std::move(scene));
}

void Raytracer::ScenesManager::addMultipleScenes(std::unique_ptr<std::vector<std::unique_ptr<Scene>>> scenes)
{
    for (auto &scene : *scenes)
        _scenes.push_back(std::move(scene));
}

void Raytracer::ScenesManager::removeScene(const std::string &path)
{
    unsigned int scenesSize = _scenes.size();

    for (unsigned int i = 0; i < scenesSize; i++) {
        if (_scenes[i]->getFileName() == path) {
            _scenes.erase(_scenes.begin() + i);
            return;
        }
    }
    throw Raytracer::RaytracerException("Scene not found");
}

void Raytracer::ScenesManager::replaceScene(std::unique_ptr<Scene> newScene, const std::string &path)
{
    unsigned int scenesSize = _scenes.size();

    for (unsigned int i = 0; i < scenesSize; i++) {
        if (_scenes[i]->getFileName() == path) {
            _scenes[i] = std::move(newScene);
            return;
        }
    }
    throw Raytracer::RaytracerException("Scene not found");
}

const std::vector<std::unique_ptr<Raytracer::Scene>>&Raytracer::ScenesManager::getScenes() const {
    return _scenes;
}

Raytracer::Scene &Raytracer::ScenesManager::getSceneActual() const
{
    if (_sceneActual < 0 || _sceneActual >= _scenes.size())
        throw Raytracer::RaytracerException("Actual scene is not valid");
    return *_scenes[_sceneActual];
}

void Raytracer::ScenesManager::setSceneActual(int scene)
{
    _sceneActual = scene;
}

int Raytracer::ScenesManager::getNumberScenes() const
{
    return _scenes.size();
}

int Raytracer::ScenesManager::getIndexActualScene() const
{
    return _sceneActual;
}

void Raytracer::ScenesManager::moveCamera(std::string key, bool isCtrlPressed) const
{
    ACam &cam = getCam();

    switch (key[4]) {
        case 'Z':
            isCtrlPressed ? cam.rotate({0.1, 0, 0}) : cam.translate({0, 1, 0});
            break;
        case 'Q':
            isCtrlPressed ? cam.rotate({0, 0.1, 0}) : cam.translate({0, 0, 1});
            break;
        case 'S':
            isCtrlPressed ? cam.rotate({-0.1, 0, 0}) : cam.translate({0, -1, 0});
            break;
        case 'D':
            isCtrlPressed ? cam.rotate({0, -0.1, 0}) : cam.translate({0, 0, -1});
            break;
        case 'A':
            isCtrlPressed ? cam.rotate({0, 0, -0.1}) : cam.translate({1, 0, 0});
            break;
        case 'E':
            isCtrlPressed ? cam.rotate({0, 0, 0.1}) : cam.translate({-1, 0, 0});
            break;
        default:
            break;
    }
    getCam().setEdit(true);
}

Raytracer::ACam &Raytracer::ScenesManager::getCam() const
{
    const std::vector<Raytracer::IEntity *> &entities = _scenes[_sceneActual]->getEntities();

    for (const auto &entity : entities) {
        if (entity->getType() == CompType::CAM) {
            ACam *cam = static_cast<ACam *>(entity);
            return *cam;
        }
    }
    throw Raytracer::RaytracerException("Camera not found");
}

bool Raytracer::ScenesManager::isCtrlActive() const
{
    return _isCtrlActive;
}

void Raytracer::ScenesManager::update(Raytracer::EventManager &eventManager, Raytracer::Observer &observer)
{
    const std::string key = eventManager.isEventTriggered(keyZ) ? keyZ :
                        eventManager.isEventTriggered(keyQ) ? keyQ :
                        eventManager.isEventTriggered(keyS) ? keyS :
                        eventManager.isEventTriggered(keyD) ? keyD :
                        eventManager.isEventTriggered(keyA) ? keyA :
                        eventManager.isEventTriggered(keyE) ? keyE :
                        "";

    _isCtrlActive = eventManager.isCtrlActive();
    if (eventManager.isEventTriggered(keyLeft)) {
        _sceneActual > 0 ? setSceneActual(_sceneActual - 1) : setSceneActual(_scenes.size() - 1);
        observer.subscribe(getSceneActual().getFileName());
    }
    if (eventManager.isEventTriggered(keyRight)) {
        _sceneActual == _scenes.size() - 1 ? setSceneActual(0) : setSceneActual(_sceneActual + 1);
        observer.subscribe(getSceneActual().getFileName());
    }
    if (!key.empty())
        moveCamera(key, eventManager.isCtrlActive());
    if (eventManager.isEventTriggered(keyEnter) && getCam().isEdited()) {
        _scenes[_sceneActual]->calculateImage();
        getCam().setEdit(false);
    }
    if (!_scenes[_sceneActual]->getIsCalculate())
        _scenes[_sceneActual]->calculateImage();
    _scenes[_sceneActual]->update(eventManager);
}
