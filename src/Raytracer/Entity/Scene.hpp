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

namespace Raytracer {
    class Scene {
    public:
        Scene();

        ~Scene();

        void addEntity(IEntity &entity);

        IEntity &getEntity(int index) const;

        IEntity &getEntity(const std::string &name) const;

        void calculateImage();

        Image &getImage() const;

    protected:
    private:
        std::vector<std::unique_ptr<IEntity>> _entities;
        std::unique_ptr<Image> _image;
    };
};
