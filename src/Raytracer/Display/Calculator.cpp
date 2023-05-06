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
#include "ACam.hpp"
#include "AMaterial.hpp"
#include "Matrix.hpp"

Raytracer::ACam *Raytracer::Calculator::findCam(const std::vector<IEntity *> &entities)
{
    for (const auto &entity : entities) {
        if (entity && entity->getType() == Raytracer::CompType::CAM) {
            return static_cast<Raytracer::ACam*>(entity);
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

Component::Vector3f Raytracer::Calculator::getRayDirection(int x, int y, const Raytracer::ACam *cam)
{
    // Calculer les coordonnées normalisées de l'écran
    float ndc_x = (2.0f * x) / static_cast<float>(width) - 1.0f;
    float ndc_y = 1.0f - (2.0f * y) / static_cast<float>(height);

    // Calculer l'aspect ratio de l'écran
    float aRatio = static_cast<float>(width) / static_cast<float>(height);

    // Calculer la distance focale en fonction du champ de vision (fov) et de l'aspect ratio
    auto seg = cam->getType();
    float fov = cam->getFieldOfView();
    float focalLengthX = 1.0f / tanf(fov * 0.5f * (M_PI / 180.0f));
    float focalLengthY = focalLengthX * aRatio;

    // Créer un vecteur direction dans l'espace de la caméra
    Component::Vector3f directionInCameraSpace(ndc_x / focalLengthX, ndc_y / focalLengthY, -1.0f);

    // Convertir les angles d'Euler de la rotation de la caméra en une matrice de rotation
    Component::Matrix3x3 rotationMatrix = Component::Matrix3x3::fromEulerAngles(cam->getRotation());

    // Appliquer la rotation de la caméra au vecteur direction
    Component::Vector3f direction = rotationMatrix * directionInCameraSpace;

    // Normaliser le vecteur direction
    direction = direction.normalize();

    return direction;
}
Component::Color Raytracer::Calculator::castRay(const Component::Vector3f &origin, const Component::Vector3f &direction,
                                                const std::vector<IEntity *> &entities,
                                                const std::vector<Raytracer::ALight *> &lights,
                                                int recursionDepth)
{
    float t_min = std::numeric_limits<float>::max();
    IEntity &intersected_object = findClosestEntity(origin, direction, entities, t_min);
    APrimitive *primitive = static_cast<APrimitive *>(&intersected_object);

    // S'il n'y a pas d'intersection, retourner une couleur d'arrière-plan
    if (t_min == std::numeric_limits<float>::max()) {
        return Component::Color(0, 0, 0);
    }

    Component::Vector3f hitPoint = origin + direction * t_min;
    Component::Vector3f hit_normal = primitive->getNormal(hitPoint);
    IMaterial &object_material = primitive->getMaterial();
    AMaterial &material = static_cast<Raytracer::AMaterial &>(object_material);

    Component::Color final_color = calculateLighting(hitPoint, hit_normal, material, entities, lights);

    if (recursionDepth > 0 && material.getReflectivity() > 0) {
        Component::Vector3f reflectionDirection = getReflectionDirection(direction, hit_normal);
        Component::Color reflectedColor = castRay(hitPoint, reflectionDirection, entities, lights, recursionDepth - 1);
        final_color = final_color + (reflectedColor * material.getReflectivity());
    }

    // Clamp color values between 0 and 255
    final_color.clamp();
    Component::Color integerColor = final_color.toInteger();

    return integerColor;
}


Component::Color Raytracer::Calculator::calculateLighting(const Component::Vector3f &hitPoint, const Component::Vector3f &hit_normal,
                                                          const Raytracer::AMaterial &material,
                                                          const std::vector<IEntity *> &entities,
                                                          const std::vector<Raytracer::ALight *> &lights)
{
    Component::Color final_color(0, 0, 0);

    for (const auto *light_ptr : lights) {
        const Raytracer::ALight &light = *light_ptr;
        Component::Vector3f light_direction = (light.getPosition() - hitPoint).normalize();
        float light_intensity = light.getIntensity();

        // Vérifier les ombres
        bool in_shadow = checkShadows(hitPoint, hit_normal, light_direction, entities, light);

        // Calculer la couleur diffuse et spéculaire
        if (!in_shadow) {
            Component::Color diffuse_color = computeDiffuseColor(hitPoint, hit_normal, light_direction, material, light_intensity);
            Component::Color specular_color = computeSpecularColor(hitPoint, hit_normal, light_direction, material, light, light_intensity);

            // Ajouter la couleur diffuse et spéculaire
            final_color = final_color + diffuse_color + specular_color;
        }
    }

    return final_color;
}
Component::Color Raytracer::Calculator::computeDiffuseColor(const Component::Vector3f &hitPoint, const Component::Vector3f &hit_normal,
                                                            const Component::Vector3f &light_direction,
                                                            const Raytracer::AMaterial &material, float light_intensity)
{
    Component::Color diffuse_color = material.computeColor(hitPoint, hit_normal, light_direction, light_intensity, ambientLightColor, ambientLightIntensity);
    return diffuse_color;
}


Component::Color Raytracer::Calculator::computeSpecularColor(const Component::Vector3f &hitPoint, const Component::Vector3f &hit_normal,
                                                             const Component::Vector3f &light_direction, const Raytracer::AMaterial &material,
                                                             const Raytracer::ALight &light, float light_intensity)
{
    Component::Vector3f view_direction = (findCam(entities)->getPosition() - hitPoint).normalize();
    Component::Vector3f reflection_direction = getReflectionDirection(light_direction, hit_normal);

    float specular_intensity = pow(std::max(0.0f, view_direction.dot(reflection_direction)), material.getShininess());

    return light.getColor() * material.getSpecular() * light_intensity * specular_intensity;
}

Component::Vector3f Raytracer::Calculator::getReflectionDirection(const Component::Vector3f &incident, const Component::Vector3f &normal)
{
    return incident - normal * 2.0f * incident.dot(normal);
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

bool Raytracer::Calculator::checkShadows(const Component::Vector3f &hitPoint, const Component::Vector3f &hit_normal,
                                         const Component::Vector3f &light_direction, const std::vector<IEntity *> &entities,
                                         const Raytracer::ALight &light)
{
    APrimitive* primitive = nullptr;
    Ray shadow_ray(hitPoint + hit_normal * 1e-3f, light_direction);

    for (const auto &entity : entities) {
        if (entity->getType() != Raytracer::CompType::PRIMITIVE)
            continue;
        primitive = static_cast<APrimitive*>(entity);
        float t_shadow = primitive->intersect(shadow_ray);
        if (t_shadow > 0.0f && t_shadow < (light.getPosition() - hitPoint).length()) {
            return true;
        }
    }
    return false;
}

void Raytracer::Calculator::calculatePixels()
{
    try {
        ACam* camera = findCam(entities);
        std::cout << "Camera position: (" << camera->getPosition().x << ", " << camera->getPosition().y << ", " << camera->getPosition().z << ")" << std::endl;
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
                Component::Color pixelColor = castRay(camera->getPosition(), rayDirection, entities, lights);
                pixels[y][x] = pixelColor;
            }
        }
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
