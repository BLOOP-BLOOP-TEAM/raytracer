/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** _eventManager
*/

#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

namespace Raytracer {
    class EventManager {
    public:
        explicit EventManager(sf::RenderWindow &window);

        ~EventManager() = default;

        void update();

        [[nodiscard]] bool isEventTriggered(const std::string &event) const;

        [[nodiscard]] bool isCtrlActive() const;

        void clear();

    protected:
    private:
        std::vector<std::string> _events;
        sf::RenderWindow &_window;
        sf::Event _event;
        bool _isCtrlActive;
    };
}
