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
    class Scene {
    public:
        Scene();

        ~Scene();

        void addEntity(IEntity *entity);

        [[nodiscard]] IEntity &getEntity(int index) const;

        void calculateImage();

        [[nodiscard]] Image &getImage() const;

        void update(EventManager &eventManager);

    protected:
    private:
        std::vector<IEntity *> _entities;
        std::unique_ptr<Image> _image;
    };
};
