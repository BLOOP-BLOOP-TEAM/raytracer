#include <iostream>
#include <string>
#include <cmath>
#include "stb_image.h"
#include "Color.hpp"
#include "Vector3f.hpp"
#include "Skybox.hpp"

Raytracer::Skybox::Skybox(const std::string &filename)
{
    int width, height, channels;
    unsigned char *image_data = stbi_load(filename.c_str(), &width, &height, &channels, STBI_rgb_alpha);

    if (image_data) {
        m_width = width;
        m_height = height;
        m_channels = channels;
        m_data.assign(image_data, image_data + width * height * channels);
        stbi_image_free(image_data);
    } else {
        throw std::runtime_error("Failed to load skybox image");
    }
}

Component::Color Raytracer::Skybox::getColorFromRay(const Component::Vector3f &direction)
{
    // Convertir le rayon en coordonnées sphériques
    float theta = std::acos(direction.y);
    float phi = std::atan2(direction.z, direction.x) + M_PI;

    // Convertir les coordonnées sphériques en coordonnées UV
    float u = phi / (2 * M_PI);
    float v = theta / M_PI;

    // Obtenir le pixel de l'image de la skybox
    unsigned char *pixel = getPixel(u, v);

    // Utilisez les valeurs RGBA du pixel pour déterminer la couleur de la skybox
    unsigned char r = pixel[0];
    unsigned char g = pixel[1];
    unsigned char b = pixel[2];
    unsigned char a = pixel[3];

    // Convertir les valeurs de pixel en couleur
    Component::Color finalColor(r, g, b);

    return finalColor;
}

unsigned char *Raytracer::Skybox::getPixel(float u, float v)
{
    int x = static_cast<int>(u * m_width) % m_width;
    int y = static_cast<int>(v * m_height) % m_height;
    int index = (x + y * m_width) * m_channels;
    return &m_data[index];
}

Raytracer::Skybox::~Skybox()
{
    m_data.clear();
}
