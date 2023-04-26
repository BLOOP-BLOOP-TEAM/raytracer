/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ACam
*/

#pragma once

#include "ICam.hpp"
#include "AEntity.hpp"

namespace Raytracer {
    class ACam : public ICam, public AEntity {
    public:
        ACam();

        ~ACam();

    protected:
    private:
    };
};
