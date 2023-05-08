/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ACam
*/

#pragma once

#include <string>
#include <iostream>
#include "ICam.hpp"
#include "AEntity.hpp"
#include "Vector3f.hpp"
#include "AEntity.hpp"
#include "ICam.hpp"

namespace Raytracer {
    class ACam : public ICam, public AEntity {
    public:
        ACam(const std::string &typeCam, const Component::Vector3f &position, const Component::Vector3f &rotation,
             bool isEdited, double fieldOfView, const Component::Vector3f &resolution);

        ~ACam() override = default;

        [[nodiscard]] double getFieldOfView() const final;

        [[nodiscard]] Component::Vector3f getResolution() const override;

        [[nodiscard]] const Component::Vector3f &getRotation() const;
        void setRotation(const Component::Vector3f &rotation);
        [[nodiscard]] const std::string &getTypeCam() const;
        [[nodiscard]] bool isEdited() const;
        void setEdit(bool status);

    protected:
    private:
        std::string _typeCam;
        Component::Vector3f _rotation;
        Component::Vector3f _resolution;
        double _fieldOfView;
        bool _isEdited;
    };
};
