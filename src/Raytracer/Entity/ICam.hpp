/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ICam
*/

#pragma once

#include "IPrimitive.hpp"
#include "Vector3f.hpp"

namespace Raytracer {
    /**
     * @brief The ICam class
     * 
     * The ICam class defines the common methods of Camera objects.
     */
    class ICam {
        public:
            virtual ~ICam() = default;
    
            /**
             * @brief Gets the field of view of the camera
             */
            virtual float getFieldOfView() const = 0;
    };
};
