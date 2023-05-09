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
    /**
    * @brief The APrimitive class
    * 
    * The APrimitive class defines the common methods that a Primitive will have, and extends the AEntity class.
    */
    class APrimitive : public IPrimitive, public AEntity {
        public:
            /**
             * @brief Constructor for APrimitive
             * 
             * @param type The type of the primitive as a string
             * @param position The position of the primitive as a Component::Vector3f object
             * @param rotation The rotation of the primitive as a Component::Vector3f object
             */
            APrimitive(std::string type, const Component::Vector3f &position, const Component::Vector3f &rotation);

             ~APrimitive() override = default;

            /**
             * @brief Function that checks for an intersection with a ray
             * 
             * Calculates whether the specified ray intersects with the object.
             * 
             * @param ray The Ray object to check for intersection
             */
            [[nodiscard]] double intersect(const Ray &ray) const override = 0;
    
            /**
             * @brief Function that sets the material of the primitive
             * 
             * @param material Pointer on IMaterial object to set as the material of the primitive
             */
            void setMaterial(IMaterial *material) override;

            /**
             * @brief Function that gets the normal of the primitive at the specified hit point
             * 
             * @param hitPoint The hit point as a Component::Vector3f object
             */
            [[nodiscard]] Component::Vector3f getNormal(const Component::Vector3f &hitPoint) const override = 0;

            /**
             * @brief Function that gets the material of the primitive
             */
            [[nodiscard]] IMaterial &getMaterial() const override;

            /**
             * @brief Function that gets the type of the primitive
             */
            [[nodiscard]] const std::string &getTypePrimitive() const;
        protected:
        private:
            std::string _typePrimitive;
            IMaterial *_material;
            std::unique_ptr<IMaterial> _defaultMaterial;
    };
};
