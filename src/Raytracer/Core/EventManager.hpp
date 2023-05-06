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
    /**
     * @brief The EventManager class provides an interface for handling events in a SFML window.
     */
    class EventManager {
        public:
            /**
             * @brief Constructor for EventManager class.
             * 
             * @param window The SFML window to listen for events on.
             */
            explicit EventManager(sf::RenderWindow &window);

            ~EventManager() = default;

            /**
             * @brief Updates the list of events that have occurred since the last update.
             */
            void update();

            /**
             * @brief Checks if the given event has occurred.
             * 
             * @param event The name of the event to check for.
             */
            [[nodiscard]] bool isEventTriggered(const std::string &event) const;

            /**
             * @brief Clears the list of events that have occurred since the last update.
             */
            void clear();

        protected:
        private:
            std::vector<std::string> _events;
            sf::RenderWindow &_window;
            sf::Event _event;
    };
};
