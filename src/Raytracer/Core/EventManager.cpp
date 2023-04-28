/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** _eventManager
*/

#include <SFML/Graphics.hpp>
#include "EventManager.hpp"

Raytracer::EventManager::EventManager(sf::RenderWindow &window) : _window(window)
{
}

void Raytracer::EventManager::update()
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                _window.close();
            if (event.key.code == sf::Keyboard::Space)
                _events.push_back("space");
        }
    }
}

bool Raytracer::EventManager::isEventTriggered(const std::string &event) const
{
    for (auto &e : _events) {
        if (e == event)
            return true;
    }
    return false;
}

void Raytracer::EventManager::clear()
{
    _events.clear();
}
