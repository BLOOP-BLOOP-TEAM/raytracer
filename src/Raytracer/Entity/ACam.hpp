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
             * @param resolution a Vector3f representing the resolution of the camera
             * @param isEdited a bool to check if the cam is edited
             */
            ACam(const std::string &typeCam, const Component::Vector3f &position, const Component::Vector3f &rotation,
                bool isEdited, double fieldOfView, const Component::Vector3f &resolution);

            ~ACam() override { std::cout << "ACam::~ACam" << std::endl; };

            /**
             * @brief Returns the field of view of the camera
             */
            [[nodiscard]] double getFieldOfView() const override;

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

            /**
             * @brief Get the resolution of the camera
             */
            [[nodiscard]] Component::Vector3f getResolution() const override;

            /**
             * @brief Check if the camera is edited
             */
            [[nodiscard]] const bool isEdited() const;
            
            /**
             * @brief Set the _isEdited bool to true or false
             */
            void setEdit(bool status);

        protected:
        private:
            std::string _typeCam;
            Component::Vector3f _resolution;
            double _fieldOfView;
            bool _isEdited;

    };
};
