/*
** EPITECH PROJECT, 2023
** miror_raytracer
** File description:
** Observer
*/

#include "Observer.hpp"

static const std::string FOLDER_NAME = "Scenes";

Raytracer::Observer(const std::vector<std::string> allScenes) {
    int nbrFiles = allScenes.size();

    for (int i = 0; i < nbrFiles; i++)
        subscribe(allScenes[i]);
}

void Raytracer::subscribe(const std::string &path) {
    if (std::find(_allSubScenes.begin(), _allSubScenes.end(), path) != _allSubScenes.end())
        return;
    _allSubScenes.push_back(path);
    _lastUpdates.push_back(getTimeStamp(path));
}

void Raytracer::unsubscribe(const std::string &path) {
    size_t index = 0;
    auto it = std::find(_allSubScenes.begin(), _allSubScenes.end(), path);

    if (it != _allSubScenes.end()) {
        index = it - _allSubScenes.begin();
        _allSubScenes.erase(_allSubScenes.begin() + index);
        _lastUpdates.erase(_lastUpdates.begin() + index);
        // appelle de la fonction qui détruit la scène
    }
}

std::time_t Raytracer::getTimeStamp(const std::string &path) {
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

void Raytracer::notify(const std::string &path)
{
    int index = 0;
    // appelle de la fonction qui load la scène

    for (const auto &subScene : _allSubScenes) {
        if (subScene == path)
            break;
        index += 1;
    }
    _lastUpdates[index] = getTimeStamp(path);
}

void Raytracer::checkEditedFiles() {
    std::vector<bool> filesStatus;
    int nbrFiles = _allSubScenes.size();

    for (const auto &path : _allSubScenes) {
        const std::time_t timeStamp = getTimeStamp(path);

        if (timeStamp == -1)
            return;
        if (timeStamp > _lastUpdates[index])
            filesStatus.push_back(true);
        else
            filesStatus.push_back(false);
    }
    for (int i = 0; i < nbrFiles; i++) {
        if (filesStatus[i]) {
            std::cout << "Lancement de load sur la scene : " << _allSubScenes[i] << std::endl;
            notify(_allSubScenes[i]);
        }
    }
}
