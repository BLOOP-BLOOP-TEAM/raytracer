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

namespace Raytracer {
    class ACam : public ICam, public AEntity {
    public:
        ACam(const std::string &typeCam, const Component::Vector3f &position, const Component::Vector3f &rotation,
             float field_of_view, float aspect_ratio);

        ~ACam() = default;

        float getFieldOfView() const override;
        float getAspectRatio() const override;

        const Component::Vector3f &getRotation() const;
        void setRotation(const Component::Vector3f &rotation);

    protected:
    private:
        std::string _typeCam;
        Component::Vector3f _rotation;
        float _fieldOfView;
        float _aspectRatio;
    };
};

