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
    /**
     * @brief The ACam class
     * 
     * This class represents a camera entity and inherits from both ICam and AEntity.
     */
    class ACam : public ICam, public AEntity {
        public:
            /**
             * @brief Constructor of ACam
             * 
             * @param typeCam a string representing the type of camera
             * @param position a Vector3f object representing the position of the camera
             * @param rotation a Vector3f object representing the rotation of the camera
             * @param fieldOfView a double value representing the field of view of the camera
             */
            ACam(const std::string &typeCam, const Component::Vector3f &position, const Component::Vector3f &rotation,
                double fieldOfView);

            ~ACam() override { std::cout << "ACam::~ACam" << std::endl; };

            /**
             * @brief Returns the field of view of the camera
             */
            [[nodiscard]] double getFieldOfView() const override;

            /**
             * @brief Returns the rotation of the camera
             */
            [[nodiscard]] const Component::Vector3f &getRotation() const;

            /**
             * @brief Sets the rotation of the camera
             * 
             * @param rotation a Vector3f object representing the new rotation of the camera
             */
            void setRotation(const Component::Vector3f &rotation);

            /**
             * @brief Returns the type of camera
             */
            [[nodiscard]] const std::string &getTypeCam() const;

        protected:
        private:
            std::string _typeCam;
            Component::Vector3f _rotation;
            double _fieldOfView;
    };
};

