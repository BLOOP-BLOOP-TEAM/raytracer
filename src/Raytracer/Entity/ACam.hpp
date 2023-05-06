/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ACam
*/

#pragma once

#include <string>
#include "ICam.hpp"
#include "AEntity.hpp"
#include "Vector3f.hpp"
#include "AEntity.hpp"
#include "ICam.hpp"
#include <iostream>
namespace Raytracer {
    class ACam : public ICam, public AEntity {
    public:
        ACam(const std::string &typeCam, const Component::Vector3f &position, const Component::Vector3f &rotation,
             double field_of_view);

        ~ACam() override = default;

        [[nodiscard]] double getFieldOfView() const final;

        [[nodiscard]] const Component::Vector3f &getRotation() const;
        void setRotation(const Component::Vector3f &rotation);
        [[nodiscard]] const std::string &getTypeCam() const;
        [[nodiscard]] const bool isEdited() const;
        void setEdit(bool status);

    protected:
    private:
        std::string _typeCam;
        Component::Vector3f _rotation;
        double _fieldOfView;
        bool _isEdited;
    };
};
