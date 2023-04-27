/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** APrimitive
*/

#pragma once

#include <string>
#include "IPrimitive.hpp"
#include "AEntity.hpp"

namespace Raytracer {
    class APrimitive : public IPrimitive, public AEntity {
    public:
        APrimitive(const std::string &type, const Component::Vector3f &position);

        ~APrimitive();

        void setMaterial(std::unique_ptr<IMaterial> material) override;

    protected:
    private:
        std::string _typePrimitive;
        std::unique_ptr<IMaterial> _material;
    };
};
