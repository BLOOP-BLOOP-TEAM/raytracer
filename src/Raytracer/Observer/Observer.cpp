/*
** EPITECH PROJECT, 2023
** miror_raytracer
** File description:
** Observer
*/

#include "Observer.hpp"

static const std::string FOLDER_NAME = "Scenes";

Observer::Observer(const std::vector<std::string> allScenes) {
    int nbrFiles = allScenes.size();

    for (int i = 0; i < nbrFiles; i++)
        subscribe(allScenes[i]);
}

Observer::~Observer() {}

void Observer::subscribe(std::string path) {
    _allSubScenes.push_back(path);
    _lastUpdates.push_back(getTimeStamp(path));
}

std::time_t Observer::getTimeStamp(std::string path) {
    std::filesystem::file_time_type lastWriteTime = std::filesystem::last_write_time(path);
    auto timePoint_lastWriteTime = std::chrono::time_point_cast<std::chrono::system_clock::duration>(lastWriteTime - std::filesystem::file_time_type::clock::now() + std::chrono::system_clock::now());
    std::time_t timeStamp = std::chrono::system_clock::to_time_t(timePoint_lastWriteTime);

    return timeStamp;
}

void Observer::notify(std::string path)
{
    int index = 0;
    // appelle de la fonction qui load la scène

    for (int i = 0; i < _allSubScenes.size(); i++) {
        if (_allSubScenes[i] == path) {
            index = i;
            break;
        }
    }
    _lastUpdates[index] = getTimeStamp(path);
}

void Observer::checkEditedFiles() {
    std::vector<bool> filesStatus;
    int nbrFiles = _allSubScenes.size();

    for (int i = 0; i < nbrFiles; i++) {
        std::string path = _allSubScenes[i];
        std::time_t timeStamp = getTimeStamp(path);

        if (timeStamp > _lastUpdates[i])
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
