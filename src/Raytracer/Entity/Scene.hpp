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
#include "Skybox.hpp"
#include "EventManager.hpp"

namespace Raytracer {
    class Scene {
    public:
        Scene(const std::string &name, const std::string &fileName);

        ~Scene();

        [[nodiscard]] Component::Vector3f getResolution() const;

        void addEntity(IEntity *entity);

        void addMaterial(IMaterial *material);

        void addSkybox(ISkybox *skybox);

        [[nodiscard]] ISkybox *getSkybox();

        [[nodiscard]] IEntity &getEntity(int index) const;

        [[nodiscard]] const std::vector<IEntity *> &getEntities() const;

        [[nodiscard]] IMaterial &getMaterial(int index) const;

        [[nodiscard]] const std::vector<IMaterial *> &getMaterials() const;

        void calculateImage();

        [[nodiscard]] Image &getImage() const;

        [[nodiscard]] const std::string &getFileName();

        void update(EventManager &eventManager);

        void setIsCalculate();

        [[nodiscard]] const bool &getIsCalculate() const;

    protected:
    private:
        std::vector<IEntity *> _entities;
        std::vector<IMaterial *> _materials;
        Skybox *_skybox;
        std::unique_ptr<Image> _image;
        std::string _fileName;
        std::string _name;
        bool _isCalculate;
    };
};
