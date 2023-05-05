/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Scene
*/

#pragma once

#include <vector>
#include <string>
#include <memory>
#include "IEntity.hpp"
#include "Image.hpp"
#include "EventManager.hpp"

namespace Raytracer {
    /**
     * @brief the Scene class
     * 
     * This will contain all object that a scene needs
     */
    class Scene {
    public:
        /**
         * @brief the constructor of the Scene
         *
         * This constructor will init the _image variable and 
         * the _fileName variable with the given parameter
         *
         * @param name string that correspond to the name of the file
         */
        Scene(const std::string &name);

        ~Scene();

        /**
         * @brief function that add an entity
         *
         * This function will add an entity to the _entities variable
         *
         * @param entity the Entity object to add in _entities.
         */
        void addEntity(IEntity *entity);

        /**
         * @brief function that add an material
         *
         * This function will add an material to the _materials variable
         *
         * @param material the Entity object to add in _entities.
         */
        void addMaterial(IMaterial *material);

        /**
         * @brief function that get an entity
         *
         * This function will get the entity inside the _entities variable
         * with the help of the index given.
         *
         * @param index an int that is the index where you get the entity
         */
        [[nodiscard]] IEntity &getEntity(int index) const;

        /**
         * @brief function that get all entities
         *
         * This function will get all the entities contains inside _entities.
         */
        [[nodiscard]] const std::vector<IEntity *> &getEntities() const;

        /**
         * @brief function that get an material
         *
         * This function will get the material inside the _materials variable
         * with the help of the index given.
         *
         * @param index an int that is the index where you get the material
         */
        [[nodiscard]] IMaterial &getMaterial(int index) const;

        /**
         * @brief function that get all materials
         *
         * This function will get all the entities contains inside _materials.
         */
        [[nodiscard]] const std::vector<IMaterial *> &getMaterials() const;

        /**
         * @brief function that calculate an image
         * 
         * This function will use the method of the image to calculate
         * every pixel we want to print.
         */
        void calculateImage();

        /**
         * @brief function that get the image
         * 
         * This function will return the image contained inside _image
         */
        [[nodiscard]] Image &getImage() const;

        /**
         * @brief function that get the file name
         * 
         * This function will get the file name contained inside _fileName
         * This variable is init inside the constructor @see Scene()
         */
        [[nodiscard]] const std::string &getFileName();

        /**
         * @brief function that update the scene
         * 
         * This function update the all the object of the scene.
         * 
         * @param eventManager an EventManager object that handle all the events.
         */
        void update(EventManager &eventManager);

        /**
         * @brief function that set _isCalculate
         * 
         * This function will turn the _isCalculate variable to true or false
         * taking in consideration the actual data set to isCalculate.
         */
        void setIsCalculate();
        
        /**
         * @brief function that get _isCalculate
         * 
         * This function will get the actual state of _isCalculate
         */
        [[nodiscard]] const bool &getIsCalculate();

    protected:
    private:
        std::vector<IEntity *> _entities;
        std::vector<IMaterial *> _materials;
        std::unique_ptr<Image> _image;
        std::string _fileName;
        bool _isCalculate;
    };
};
