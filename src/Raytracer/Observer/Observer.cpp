/*
** EPITECH PROJECT, 2023
** miror_raytracer
** File description:
** Observer
*/

#include "ConfigLoader.hpp"
#include "Observer.hpp"

static const std::string FOLDER_NAME = "Scenes/";
static const std::string keyLeft = "KEY_LEFT_PRESSED";
static const std::string keyRight = "KEY_RIGHT_PRESSED";

Raytracer::Observer::Observer(ScenesManager &sceneManager) : _sceneManager(sceneManager)
{
}

void Raytracer::Observer::subscribe(const std::string &path) {
    if (std::find(_allSubScenes.begin(), _allSubScenes.end(), path) != _allSubScenes.end())
        return;
    _allSubScenes.push_back(path);
    _lastUpdates.push_back(getTimeStamp(path));
}

void Raytracer::Observer::unsubscribe(const std::string &path) {
    std::string realPath = path;
    size_t index = 0;
    auto it = std::find(_allSubScenes.begin(), _allSubScenes.end(), realPath);

    if (it != _allSubScenes.end()) {
        index = it - _allSubScenes.begin();
        _allSubScenes.erase(_allSubScenes.begin() + index);
        _lastUpdates.erase(_lastUpdates.begin() + index);
        _sceneManager.removeScene(realPath);
        if (_sceneManager.getNumberScenes() == 0)
            return;
        if (_sceneManager.getIndexActualScene() == _sceneManager.getNumberScenes())
            _sceneManager.setSceneActual(0);
        subscribe(_sceneManager.getSceneActual().getFileName());
    }
}

std::time_t Raytracer::Observer::getTimeStamp(const std::string &path) {
    if (!std::filesystem::exists(path)) {
        std::cout << "Delete la scene" << std::endl;
        unsubscribe(path);
        return -1;
    }

    std::filesystem::file_time_type lastWriteTime = std::filesystem::last_write_time(path);
    auto timePoint_lastWriteTime = std::chrono::time_point_cast<std::chrono::system_clock::duration>(lastWriteTime - std::filesystem::file_time_type::clock::now() + std::chrono::system_clock::now());
    std::time_t timeStamp = std::chrono::system_clock::to_time_t(timePoint_lastWriteTime);

    return timeStamp;
}

void Raytracer::Observer::replaceScene(const std::string &path)
{
    std::unique_ptr<Raytracer::Scene> newScene;

    newScene = Raytracer::ConfigLoader::loadConfigFile(path);

    if (!newScene) {
        std::cout << "Delete la scene" << std::endl;
        unsubscribe(path);
        return;
    }
    _sceneManager.replaceScene(std::move(newScene), path);
}

void Raytracer::Observer::notify(const std::string &path)
{
    int index = 0;

    for (const auto &subScene : _allSubScenes) {
        if (subScene == path)
            break;
        index += 1;
    }
    if (index == _allSubScenes.size())
        return;
    replaceScene(path);
    _lastUpdates[index] = getTimeStamp(path);
}

bool Raytracer::Observer::isFileExist(const std::string &path) {
    std::vector<std::string> allFileNames;

    for (const auto &scene : _sceneManager.getScenes())
        allFileNames.push_back(scene->getFileName());
    for (const auto &scenePath : allFileNames) {
        if (scenePath == (FOLDER_NAME + path))
            return true;
    }
    return false;
}

void Raytracer::Observer::checkNewFiles() {
    for (const auto &entry : std::filesystem::directory_iterator(FOLDER_NAME)) {
        std::string path = entry.path().filename();
        std::string extension = entry.path().filename().extension();

        if (extension != ".cfg")
            continue;
        if (isFileExist(path))
            continue;
        else
            _sceneManager.addScene(ConfigLoader::loadConfigFile(FOLDER_NAME + path));
    }
}

void Raytracer::Observer::checkEditedFiles() {
    std::vector<bool> filesStatus;
    int nbrFiles = _allSubScenes.size();
    int index = 0;

    checkNewFiles();
    for (const auto &path : _allSubScenes) {
        const std::time_t timeStamp = getTimeStamp(path);

        if (timeStamp == -1)
            return;
        if (timeStamp > _lastUpdates[index])
            filesStatus.push_back(true);
        else
            filesStatus.push_back(false);
        index += 1;
    }
    for (int i = 0; i < nbrFiles; i++) {
        if (filesStatus[i]) {
            std::cout << "Lancement de load sur la scene : " << _allSubScenes[i] << std::endl;
            notify(_allSubScenes[i]);
        }
    }
}
