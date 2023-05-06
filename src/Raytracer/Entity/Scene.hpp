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
     * @brief The Scene class
     * 
     * This will contain all object that a scene needs
     */
    class Scene {
    public:
        /**
         * @brief The constructor of the Scene
         *
         * This constructor will init the _image variable and 
         * the _fileName variable with the given parameter
         *
         * @param name string reference that correspond to the name given to the scene
         * @param fileName string reference that correpsond to the name of the file
         */
        Scene(const std::string &name, const std::string &fileName);

        ~Scene();

        /**
         * @brief Function that add an entity
         *
         * This function will add an entity to the _entities variable
         *
         * @param entity the Entity object to add in _entities.
         */
        void addEntity(IEntity *entity);

        /**
         * @brief Function that add an material
         *
         * This function will add an material to the _materials variable
         *
         * @param material the Entity object to add in _entities.
         */
        void addMaterial(IMaterial *material);

        /**
         * @brief Function that get an entity
         *
         * This function will get the entity inside the _entities variable
         * with the help of the index given.
         *
         * @param index an int that is the index where you get the entity
         */
        [[nodiscard]] IEntity &getEntity(int index) const;

        /**
         * @brief Get the resolution of the cam in the scene
         */
        Component::Vector3f getResolution() const;

        /**
         * @brief Function that get all entities
         *
         * This function will get all the entities contains inside _entities.
         */
        [[nodiscard]] const std::vector<IEntity *> &getEntities() const;

        /**
         * @brief Function that get an material
         *
         * This function will get the material inside the _materials variable
         * with the help of the index given.
         *
         * @param index an int that is the index where you get the material
         */
        [[nodiscard]] IMaterial &getMaterial(int index) const;

        /**
         * @brief Function that get all materials
         *
         * This function will get all the entities contains inside _materials.
         */
        [[nodiscard]] const std::vector<IMaterial *> &getMaterials() const;

        /**
         * @brief Function that calculate an image
         * 
         * This function will use the method of the image to calculate
         * every pixel we want to print.
         */
        void calculateImage();

        /**
         * @brief Function that get the image
         * 
         * This function will return the image contained inside _image
         */
        [[nodiscard]] Image &getImage() const;

        /**
         * @brief Function that get the file name
         * 
         * This function will get the file name contained inside _fileName
         * This variable is init inside the constructor @see Scene()
         */
        [[nodiscard]] const std::string &getFileName();

        /**
         * @brief Function that update the scene
         * 
         * This function update the all the object of the scene.
         * 
         * @param eventManager an EventManager object that handle all the events.
         */
        void update(EventManager &eventManager);

        /**
         * @brief Function that set _isCalculate
         * 
         * This function will turn the _isCalculate variable to true or false
         * taking in consideration the actual data set to isCalculate.
         */
        void setIsCalculate();
        
        /**
         * @brief Function that get _isCalculate
         * 
         * This function will get the actual state of _isCalculate
         */
        [[nodiscard]] const bool &getIsCalculate() const;

    protected:
    private:
        std::vector<IEntity *> _entities;
        std::vector<IMaterial *> _materials;
        std::unique_ptr<Image> _image;
        std::string _fileName;
        std::string _name;
        bool _isCalculate;
    };
};
