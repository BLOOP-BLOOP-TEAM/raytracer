/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AMaterial
*/

#include <utility>
#include "AMaterial.hpp"

Raytracer::AMaterial::AMaterial(std::string type, double refractivity, double refractiveIndex, double reflectivity,
                                double diffuseFactor, const Component::Color &diffuse, double specular,
                                double shininess) : _type(std::move(type)), _refractivity(refractivity),
                                                    _refractiveIndex(refractiveIndex), _reflectivity(reflectivity),
                                                    _diffuseFactor(diffuseFactor), _diffuse(diffuse),
                                                    _specular(specular), _shininess(shininess)
                                {

}


const std::string &Raytracer::AMaterial::getType()
{
    return (_type);
}

double Raytracer::AMaterial::getRefractivity() const
{
    return _refractivity;
}

double Raytracer::AMaterial::getRefractiveIndex() const
{
    return _refractiveIndex;
}

Component::Color Raytracer::AMaterial::getDiffuse() const
{
    return _diffuse;
}

double Raytracer::AMaterial::getDiffuseFactor() const
{
    return _diffuseFactor;
}

double Raytracer::AMaterial::getSpecular() const
{
    return _specular;
}

double Raytracer::AMaterial::getShininess() const
{
    return _shininess;
}

double Raytracer::AMaterial::getReflectivity() const
{
    return _reflectivity / (255 * 2);
}
