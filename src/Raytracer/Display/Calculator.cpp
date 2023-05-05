/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Calculator
*/

#include "CompType.hpp"
#include "APrimitive.hpp"
#include "Calculator.hpp"
#include "Ray.hpp"
#include "Matrix.hpp"

Raytracer::ACam &Raytracer::Calculator::findCam(const std::vector<IEntity *> &entities)
{
    for (const auto &entity : entities) {
        if (entity->getType() == Raytracer::CompType::CAM) {
            return *static_cast<Raytracer::ACam*>(entity);
        }
    }
    throw std::runtime_error("No camera found in the scene.");
}

std::vector<Raytracer::ALight *> Raytracer::Calculator::findLights(const std::vector<IEntity *> &entities)
{
    std::vector<ALight *> lights = {};
    Raytracer::ALight* light = nullptr;

    for (const auto &entity : entities) {
        if (entity->getType() == Raytracer::CompType::LIGHT) {
            light = static_cast<Raytracer::ALight*>(entity);
            lights.push_back(light);
        }
    }
    return lights;
}

Component::Vector3f Raytracer::Calculator::getRayDirection(int x, int y, const Raytracer::ACam &cam)
{
    // Calculer les coordonnées normalisées de l'écran
    float ndc_x = (2.0f * x) / static_cast<float>(width) - 1.0f;
    float ndc_y = 1.0f - (2.0f * y) / static_cast<float>(height);

    // Calculer l'aspect ratio de l'écran
    float aRatio = static_cast<float>(width) / static_cast<float>(height);

    // Calculer la distance focale en fonction du champ de vision (fov) et de l'aspect ratio
    float fov = cam.getFieldOfView();
    float focalLengthX = 1.0f / tanf(fov * 0.5f * (M_PI / 180.0f));
    float focalLengthY = focalLengthX * aRatio;

    // Créer un vecteur direction dans l'espace de la caméra
    Component::Vector3f directionInCameraSpace(ndc_x / focalLengthX, ndc_y / focalLengthY, -1.0f);

    // Convertir les angles d'Euler de la rotation de la caméra en une matrice de rotation
    Component::Matrix3x3 rotationMatrix = Component::Matrix3x3::fromEulerAngles(cam.getRotation());

    // Appliquer la rotation de la caméra au vecteur direction
    Component::Vector3f direction = rotationMatrix * directionInCameraSpace;

    // Normaliser le vecteur direction
    direction = direction.normalize();

    return direction;
}

Component::Color Raytracer::Calculator::castRay(const Component::Vector3f &origin, const Component::Vector3f &direction,
                                                const std::vector<IEntity *> &entities,
                                                const std::vector< Raytracer::ALight *> &lights)
{
    float t_min = std::numeric_limits<float>::max();
    IEntity &intersected_object = findClosestEntity(origin, direction, entities, t_min);
    APrimitive* primitive = nullptr;
    primitive = static_cast<APrimitive*>(&intersected_object);

    // S'il n'y a pas d'intersection, retourner une couleur d'arrière-plan
    if (t_min == std::numeric_limits<float>::max()) {
        return Component::Color(0, 0, 0);
    }
    return (Component::Color(255, 0, 0));
    std::cout << "t_min: " << t_min << std::endl;

//    Component::Vector3f hit_point = origin + direction * t_min;
//    Component::Vector3f hit_normal = primitive->getNormal(hit_point);
//    IMaterial &object_material = primitive->getMaterial();
//
//    // Calculer l'éclairage pour chaque lumière
//    Component::Color final_color(0, 0, 0);
//    for (const auto &light : lights) {
//        Component::Vector3f light_direction = (light->getPosition() - hit_point).normalize();
//        float light_intensity = light->getIntensity();
//
//        // Vérifier les ombres
//        bool in_shadow = checkShadows(hit_point, hit_normal, light_direction, entities, light);
//
//        // Calculer la couleur finale en fonction de l'éclairage et des ombres
//        if (!in_shadow) {
//            Component::Color diffuse_color = object_material.computeColor(hit_point, hit_normal, light_direction, light_intensity);
//
//            // Calculer l'éclairage spéculaire
//            Component::Vector3f view_direction = (origin - hit_point).normalize();
//            Component::Vector3f reflection_direction = (light_direction - hit_normal * hit_normal.dot(light_direction) * 2).normalize();
//            float specular_intensity = pow(std::max(0.0f, view_direction.dot(reflection_direction)), object_material.getShininess());
//            Component::Color specular_color = light->getColor() * object_material.getSpecular() * light_intensity * specular_intensity;
//
//            // Ajouter la couleur diffuse et spéculaire
//            final_color = final_color + diffuse_color + specular_color;
//        }
//    }
//    // Clamp color values between 0 and 255
//    final_color.clamp();
//
//    return final_color;
}

Raytracer::IEntity &Raytracer::Calculator::findClosestEntity(const Component::Vector3f &origin, const Component::Vector3f &direction,
                                                             const std::vector<IEntity *> &entities, float &t_min)
{
    IEntity *intersected_object = nullptr;
    APrimitive *primitive = nullptr;
    t_min = std::numeric_limits<float>::max();
    Ray ray(origin, direction);

    for (const auto &entity : entities) {
        if (entity->getType() != Raytracer::CompType::PRIMITIVE)
            continue;
        primitive = static_cast<APrimitive*>(entity);
        float t = primitive->intersect(ray);
        if (t > 0.0f && t < t_min) {
            t_min = t;
            intersected_object = entity;
        }
    }
    return *intersected_object;
}

bool Raytracer::Calculator::checkShadows(const Component::Vector3f &hit_point, const Component::Vector3f &hit_normal,
                                         const Component::Vector3f &light_direction, const std::vector<IEntity *> &entities,
                                         const std::shared_ptr<Raytracer::ALight> &light)
{
    APrimitive* primitive = nullptr;
    Ray shadow_ray(hit_point + hit_normal * 1e-3f, light_direction);

    for (const auto &entity : entities) {
        primitive = static_cast<APrimitive*>(entity);
        float t_shadow = primitive->intersect(shadow_ray);
        if (t_shadow > 0.0f && t_shadow < (light->getPosition() - hit_point).length()) {
            return true;
        }
    }
    return false;
}

void Raytracer::Calculator::calculatePixels()
{
    try {
        ACam& camera = findCam(entities);
        std::cout << "Camera position: (" << camera.getPosition().x << ", " << camera.getPosition().y << ", " << camera.getPosition().z << ")" << std::endl;
        std::vector<ALight *> lights = findLights(entities);
        if (lights.empty()) {
            std::cout << "No lights found" << std::endl;
        } else {
            std::cout << "Found " << lights.size() << " light(s)" << std::endl;
            for (const auto& light : lights) {
                std::cout << "Light position: (" << light->getPosition().x << ", " << light->getPosition().y << ", " << light->getPosition().z << ")" << std::endl;
            }
        }
        std::cout << "Number of entities: " << entities.size() << std::endl;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                Component::Vector3f rayDirection = getRayDirection(x, y, camera);
                Component::Color pixelColor = castRay(camera.getPosition(), rayDirection, entities, lights);
                pixels[y][x] = pixelColor;
            }
        }
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
