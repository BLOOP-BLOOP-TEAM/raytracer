/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Factory
*/

#pragma once

#include <map>
#include <string>
#include <vector>
#include <variant>
#include <functional>
#include <libconfig.h++>
#include "IEntity.hpp"

namespace Raytracer {
    /**
     * @brief The FactoryEntity class provides a factory for creating entities.
     */
    class FactoryEntity {
        public:
            FactoryEntity() = default;

            ~FactoryEntity() = default;

            /**
             * @brief Copy constructor for FactoryEntity class (deleted).
             */
            FactoryEntity(const FactoryEntity&) = delete;

            /**
             * @brief Assignment operator for FactoryEntity class (deleted).
             */
            FactoryEntity& operator=(const FactoryEntity&) = delete;

            /**
             * @brief Gets the singleton instance of FactoryEntity class.
             */
            static FactoryEntity& getInstance();

            /**
             * @brief Creates an entity with the given name and configuration.
             * 
             * @param name The name of the entity.
             * @param setting The configuration of the entity.
             */
            IEntity *createEntity(const std::string &name, const std::map<std::string, std::variant<double, int, std::string, bool>> &setting);

            /**
             * @brief Destroys the given entity.
             * 
             * @param entity A pointer to the entity to be destroyed.
             */
            void destroyEntity(IEntity *entity);

            /**
             * @brief Adds a creator function for an entity with the given name.
             * 
             * @param name The name of the entity.
             * @param funcCreate The function that creates the entity.
             * @param funcDestroy The function that destroys the entity.
             */
            void addCreator(const std::string &name, const std::function<Raytracer::IEntity *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>& funcCreate, const std::function<void(Raytracer::IEntity *entity)>& funcDestroy);

            /**
             * @brief Gets a map of entity creators.
             */
            [[nodiscard]] const std::map<std::string, std::pair<std::function<Raytracer::IEntity *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>, std::function<void(Raytracer::IEntity *entity)>>>& getEntities() const;


        private:
            std::map<std::string, std::pair<std::function<Raytracer::IEntity *(const std::map<std::string, std::variant<double, int, std::string, bool>> &)>, std::function<void(Raytracer::IEntity *entity)>>> _entities;
    };
};
