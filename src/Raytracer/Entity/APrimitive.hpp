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
        APrimitive(std::string type, const Component::Vector3f &position);

        ~APrimitive() override = default;

        [[nodiscard]] float intersect(const Ray &ray) const override;

        void setMaterial(IMaterial *material) override;

        [[nodiscard]] Component::Vector3f getNormal(const Component::Vector3f &hit_point) const override;

        [[nodiscard]] Component::Color getColor(const Component::Vector3f &hit_point) const override;

        [[nodiscard]] IMaterial &getMaterial() const override;

        [[nodiscard]] const std::string &getTypePrimitive() const;

    protected:
    private:
        std::string _typePrimitive;
        IMaterial *_material;
    };
};
