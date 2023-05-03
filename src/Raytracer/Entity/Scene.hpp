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

        void addMaterial(IMaterial *material);

        [[nodiscard]] IEntity &getEntity(int index) const;

        [[nodiscard]] const std::vector<IEntity *> &getEntities() const;

        [[nodiscard]] IMaterial &getMaterial(int index) const;

        [[nodiscard]] const std::vector<IMaterial *> &getMaterials() const;

        void calculateImage();

        [[nodiscard]] Image &getImage() const;

        void update(EventManager &eventManager);

    protected:
    private:
        std::vector<IEntity *> _entities;
        std::vector<IMaterial *> _materials;
        std::unique_ptr<Image> _image;
    };
};
