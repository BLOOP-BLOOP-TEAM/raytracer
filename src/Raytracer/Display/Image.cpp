/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Image
*/

#include "CompType.hpp"
#include "Image.hpp"

Raytracer::Image::Image(int width, int height)
        : width(width), height(height), pixels(height, std::vector<Component::Color>(width)) {}

Component::Color Raytracer::Image::get_pixel(int x, int y) const {
    return pixels[y][x];
}

void Raytracer::Image::write_ppm(const std::string &filename) const {
    std::ofstream file(filename);

    file << "P3\n";
    file << width << " " << height << "\n";
    file << MAX_COLOR << "\n";

    for (const auto &row : pixels) {
        for (const auto &pixel : row) {
            file << pixel.r << " " << pixel.g << " " << pixel.b << " ";
        }
        file << "\n";
    }

    file.close();
}

Raytracer::ACam& Raytracer::Image::findCam(const std::vector<std::unique_ptr<IEntity>> &entities) {
    for (const auto &entity : entities) {
        if (entity->getType() == Raytracer::CompType::CAM) {
            return *static_cast<ACam*>(entity.get());
        }
    }
    throw std::runtime_error("No camera found in the scene.");
}

//ca c'est pour stocker des références vers les lumières
std::vector<std::reference_wrapper<Raytracer::ALight>> Raytracer::Image::findLights(const std::vector<std::unique_ptr<IEntity>> &entities) {
    std::vector<std::reference_wrapper<ALight>> lights;
    for (const auto &entity : entities) {
        if (entity->getType() == Raytracer::CompType::LIGHT) {
            lights.push_back(std::ref(*static_cast<ALight*>(entity.get())));
        }
    }
    return lights;
}


Component::Vector3f getRayDirection(int x, int y, int screenWidth, int screenHeight, const Raytracer::ACam *camera) {
    float aspect_ratio = (float)screenWidth / (float)screenHeight;
    float x_coord = (2.0f * (x + 0.5f) / (float)screenWidth - 1.0f) * aspect_ratio;
    float y_coord = 1.0f - 2.0f * (y + 0.5f) / (float)screenHeight;

    Component::Vector3f direction = Component::Vector3f(x_coord, y_coord, -1.0f).normalize();
    return direction;
}

Component::Color castRay(const Component::Vector3f &origin, const Component::Vector3f &direction,
                         const std::vector<std::unique_ptr<Raytracer::IEntity>> &entities,
                         const std::vector<std::reference_wrapper<Raytracer::ALight>> &lights) {
    // Vous devrez implémenter la logique pour lancer un rayon à partir de l'origine dans la direction donnée,
    // interagir avec les entités et les lumières de la scène, et renvoyer la couleur résultante.
    // Pour l'instant, je vais renvoyer une couleur grise par défaut pour que le code compile sans erreurs.
    return Component::Color(128, 128, 128);
}

void Raytracer::Image::calculateImage(std::vector<std::unique_ptr<IEntity>> &entities) {
    try {
        ACam& camera = findCam(entities);
        std::vector<std::reference_wrapper<ALight>> lights = findLights(entities);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                Component::Vector3f rayDirection = getRayDirection(x, y, width, height, &camera);
                Component::Color pixelColor = castRay(camera.getPosition(), rayDirection, entities, lights);
                pixels[y][x] = pixelColor;
            }
        }
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
