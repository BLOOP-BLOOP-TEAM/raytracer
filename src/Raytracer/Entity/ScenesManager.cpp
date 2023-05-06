/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ScenesManager
*/

#include "RaytracerException.hpp"
#include "ScenesManager.hpp"

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

void Raytracer::ScenesManager::addMultipleScenes(std::vector<std::unique_ptr<Scene>> &scenes)
{
    for (auto &scene : scenes)
        _scenes.push_back(std::move(scene));
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

void Raytracer::ScenesManager::moveCamera(std::string key)
{
    ACam &cam = getCam();

    switch (key[4]) {
        case 'Z':
            cam.translate({0, 1, 0});
            break;
        case 'Q':
            cam.translate({0, 0, 1});
            break;
        case 'S':
            cam.translate({0, -1, 0});
            break;
        case 'D':
            cam.translate({0, 0, -1});
            break;
        case 'A':
            cam.translate({-1, 0, 0});
            break;
        case 'E':
            cam.translate({1, 0, 0});
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

void Raytracer::ScenesManager::update(Raytracer::EventManager &eventManager)
{
    const std::string key = eventManager.isEventTriggered(keyZ) ? keyZ :
                        eventManager.isEventTriggered(keyQ) ? keyQ :
                        eventManager.isEventTriggered(keyS) ? keyS :
                        eventManager.isEventTriggered(keyD) ? keyD :
                        eventManager.isEventTriggered(keyA) ? keyA :
                        eventManager.isEventTriggered(keyE) ? keyE :
                        "";

    if (eventManager.isEventTriggered(keyLeft))
        _sceneActual - 1 >= 0 ? setSceneActual(_sceneActual - 1) : setSceneActual(_scenes.size());
    if (eventManager.isEventTriggered(keyRight))
        _sceneActual + 1 > _scenes.size() ? setSceneActual(0) : setSceneActual(_sceneActual + 1);
    if (!key.empty())
        moveCamera(key);
    if (eventManager.isEventTriggered(keyEnter) && getCam().isEdited()) {
        _scenes[_sceneActual]->calculateImage();
        getCam().setEdit(false);
    }
    if (!_scenes[_sceneActual]->getIsCalculate())
        _scenes[_sceneActual]->calculateImage();
    _scenes[_sceneActual]->update(eventManager);
}
