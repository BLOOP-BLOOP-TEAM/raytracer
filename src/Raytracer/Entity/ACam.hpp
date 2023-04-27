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

namespace Raytracer {
    class ACam : public ICam, public AEntity {
    public:
        ACam(const std::string &typeCam, const Component::Vector3f &position, float field_of_view, float aspect_ratio);

        ~ACam() = default;

        float getFieldOfView() const override;
        float getAspectRatio() const override;

    protected:
    private:
        std::string _typeCam;
        float _fieldOfView;
        float _aspectRatio;
    };
};
