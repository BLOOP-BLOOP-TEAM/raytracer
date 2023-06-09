/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Calculator
*/

#include <thread>
#include <vector>
#include "CompType.hpp"
#include "APrimitive.hpp"
#include "Calculator.hpp"
#include "Ray.hpp"
#include "ACam.hpp"
#include "AMaterial.hpp"
#include "Matrix.hpp"
#include "ISkybox.hpp"

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

Component::Vector3f Raytracer::Calculator::getRayDirection(int x, int y, const Raytracer::ACam *cam) const
{
    double ndcX = (2.0f * x) / static_cast<double>(width) - 1.0f;
    double ndcY = 1.0f - (2.0f * y) / static_cast<double>(height);

    double aRatio = static_cast<double>(width) / static_cast<double>(height);

    double fov = cam->getFieldOfView();
    double focalLengthX = 1.0f / tanf(fov * 0.5f * (M_PI / 180.0f));
    double focalLengthY = focalLengthX * aRatio;

    Component::Vector3f directionInCameraSpace(ndcX / (focalLengthX + 1e-6), ndcY / ((focalLengthY + 1e-6)), -1.0f);

    Component::Matrix3x3 rotationMatrix = Component::Matrix3x3::fromEulerAngles(cam->getRotation());

    Component::Vector3f direction = rotationMatrix * directionInCameraSpace;

    direction = direction.normalize();

    return direction;
}

Component::Vector3f Raytracer::Calculator::getRefractionDirection(const Component::Vector3f &incident, const Component::Vector3f &normal, double refractiveIndex)
{
    double cosIncident = std::clamp(-normal.dot(incident), -1.0, 1.0);
    double eta = 1.0 / refractiveIndex;

    double k = 1.0 - eta * eta * (1.0 - cosIncident * cosIncident);

    if (k < 0) {
        return {0, 0, 0};
    } else {
        return incident * eta + normal * (eta * cosIncident - sqrt(k));
    }
}

Component::Color Raytracer::Calculator::castRay(const Component::Vector3f &origin, const Component::Vector3f &direction,
                                                const std::vector<IEntity *> &entities,
                                                const std::vector<Raytracer::ALight *> &lights,
                                                int recursionDepth = 100)
{
    double minT = std::numeric_limits<double>::max();
    IEntity &intersectedObject = findClosestEntity(origin, direction, entities, minT);
    APrimitive *primitive = static_cast<APrimitive *>(&intersectedObject);
    Component::Color finalColor = Component::Color(0, 0, 0);

    if (minT == std::numeric_limits<double>::max()) {
        if (skybox == nullptr)
            return finalColor;
        finalColor = skybox->getColorFromRay(direction);
        return finalColor;
    }
    Component::Vector3f normalizedDirection = direction.normalize();
    Component::Vector3f hitPoint = origin + normalizedDirection * minT;
    Component::Vector3f hitNormal = primitive->getNormal(hitPoint);
    IMaterial &object_material = primitive->getMaterial();
    auto &material = static_cast<Raytracer::AMaterial &>(object_material);

    Component::Color localColor = calculateLighting(hitPoint, hitNormal, material, entities, lights);
    Component::Color reflectedColor(0, 0, 0);
    Component::Color refractedColor(0, 0, 0);

    const double epsilon = 1e-6;

    if (recursionDepth > 0) {
        if (material.getReflectivity() > 0) {
            Component::Vector3f reflectionDirection = getReflectionDirection(direction, hitNormal);
            reflectedColor = castRay(hitPoint + reflectionDirection * epsilon, reflectionDirection, entities, lights, recursionDepth - 1);
        }

        if (material.getRefractivity() > 0) {
            Component::Vector3f refractionDirection = getRefractionDirection(direction, hitNormal, material.getRefractiveIndex());
            refractedColor = castRay(hitPoint + refractionDirection * epsilon, refractionDirection, entities, lights, recursionDepth - 1);
        }

        finalColor = localColor * (1 - material.getReflectivity() - material.getRefractivity()) + reflectedColor * material.getReflectivity() + refractedColor * material.getRefractivity();
    } else {
        finalColor = localColor;
    }

    finalColor.clamp();
    Component::Color integerColor = finalColor.toInteger();

    return integerColor;
}

Component::Color Raytracer::Calculator::calculateLighting(const Component::Vector3f &hitPoint, const Component::Vector3f &hitNormal,
                                                          const Raytracer::AMaterial &material,
                                                          const std::vector<IEntity *> &entities,
                                                          const std::vector<Raytracer::ALight *> &lights)
{
    Component::Color finalColor(0, 0, 0);

    for (const auto *lightPtr : lights) {
        const Raytracer::ALight &light = *lightPtr;
        Component::Vector3f lightDirection = (light.getPosition() - hitPoint).normalize();

        double lightIntensity = light.getIntensity();

        bool inShadow = checkShadows(hitPoint, hitNormal, lightDirection, entities, light);

        if (!inShadow) {
            if (light.isIlluminating(hitPoint, lightDirection)) {
                double distance = (light.getPosition() - hitPoint).length();
                double attenuation_factor = 0.01;
                double attenuation = std::pow(distance, attenuation_factor);

                Component::Color diffuseColor = computeDiffuseColor(hitPoint, hitNormal, lightDirection, material, lightIntensity / attenuation);
                Component::Color specularColor = computeSpecularColor(hitPoint, hitNormal, lightDirection, material, light, lightIntensity / attenuation);

                finalColor = finalColor + diffuseColor + specularColor;
            }
        }
    }
    return finalColor;
}

Component::Color Raytracer::Calculator::computeDiffuseColor(const Component::Vector3f &hitPoint, const Component::Vector3f &hitNormal,
                                                            const Component::Vector3f &lightDirection,
                                                            const Raytracer::AMaterial &material, double lightIntensity)
{
    Component::Color diffuseColor = material.computeColor(hitPoint, hitNormal, lightDirection, lightIntensity, ambientLightColor, ambientLightIntensity);
    return diffuseColor;
}


Component::Color Raytracer::Calculator::computeSpecularColor(const Component::Vector3f &hitPoint, const Component::Vector3f &hitNormal,
                                                             const Component::Vector3f &lightDirection, const Raytracer::AMaterial &material,
                                                             const Raytracer::ALight &light, double lightIntensity)
{
    Component::Vector3f viewDirection = (findCam(entities)->getPosition() - hitPoint).normalize();
    Component::Vector3f reflectionDirection = getReflectionDirection(lightDirection, hitNormal);

    double dotProduct = viewDirection.dot(reflectionDirection);
    double specularIntensity = 0.0;

    if (dotProduct > 0.0) {
        specularIntensity = pow(dotProduct, material.getShininess());
    }

    return light.getColor() * material.getSpecular() * lightIntensity * specularIntensity;
}

Component::Vector3f Raytracer::Calculator::getReflectionDirection(const Component::Vector3f &incident, const Component::Vector3f &normal)
{
    Component::Vector3f normalizedIncident = incident.normalize();
    Component::Vector3f normalizedNormal = normal.normalize();
    return (normalizedIncident - normalizedNormal * 2.0f * normalizedIncident.dot(normalizedNormal)).normalize();
}

Raytracer::IEntity &Raytracer::Calculator::findClosestEntity(const Component::Vector3f &origin, const Component::Vector3f &direction,
                                                             const std::vector<IEntity *> &entities, double &minT)
{
    IEntity *intersectedObject = nullptr;
    APrimitive *primitive = nullptr;
    minT = std::numeric_limits<double>::max();
    Ray ray(origin, direction);

    for (const auto &entity : entities) {

        if (entity->getType() != Raytracer::CompType::PRIMITIVE)
            continue;
        primitive = static_cast<APrimitive*>(entity);
        double t = primitive->intersect(ray);
        if (t > 0.0f && t < minT) {
            minT = t;
            intersectedObject = entity;
        }
    }
    return *intersectedObject;
}

bool Raytracer::Calculator::checkShadows(const Component::Vector3f &hitPoint, const Component::Vector3f &hitNormal,
                                         const Component::Vector3f &lightDirection, const std::vector<IEntity *> &entities,
                                         const Raytracer::ALight &light)
{
    APrimitive* primitive = nullptr;
    Ray shadowRay(hitPoint + hitNormal, lightDirection);

    for (const auto &entity : entities) {
        if (entity->getType() != Raytracer::CompType::PRIMITIVE)
            continue;
        primitive = static_cast<APrimitive*>(entity);
        double shadowT = primitive->intersect(shadowRay);
        if (shadowT > 0.0f && shadowT < (light.getPosition() - hitPoint).length()) {
            return true;
        }
    }
    return false;
}

Component::Color Raytracer::Calculator::getAverageColor(int x, int y, const Raytracer::ACam *camera,
                                                        const std::vector<IEntity *> &entities,
                                                        const std::vector<Raytracer::ALight *> &lights,
                                                        int subPixelsPerAxis = 1)
{
    int numSubPixels = subPixelsPerAxis * subPixelsPerAxis;
    Component::Color pixelColorSum(0, 0, 0);

    for (int subY = 0; subY < subPixelsPerAxis; ++subY) {
        for (int subX = 0; subX < subPixelsPerAxis; ++subX) {
            double offsetX = static_cast<double>(subX) / subPixelsPerAxis;
            double offsetY = static_cast<double>(subY) / subPixelsPerAxis;
            Component::Vector3f rayDirection = getRayDirection(x + offsetX, y + offsetY, camera);
            pixelColorSum = pixelColorSum + castRay(camera->getPosition(), rayDirection, entities, lights);
        }
    }

    Component::Color pixelColor(static_cast<int>(pixelColorSum.r / numSubPixels),
                                static_cast<int>(pixelColorSum.g / numSubPixels),
                                static_cast<int>(pixelColorSum.b / numSubPixels));
    return pixelColor;
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

        int num_threads = std::thread::hardware_concurrency();
        std::vector<std::thread> threads(num_threads);
        int chunk_size = height / num_threads;

        for (int i = 0; i < num_threads; ++i) {
            threads[i] = std::thread([this, i, chunk_size, num_threads, camera, &lights]() {
                int start = i * chunk_size;
                int end = (i == num_threads - 1) ? height : start + chunk_size;

                for (int y = start; y < end; ++y) {
                    for (int x = 0; x < width; ++x) {
                        pixels[y][x] = getAverageColor(x, y, camera, entities, lights);
                    }
                }
            });
        }

        for (auto &t : threads) {
            t.join();
        }

    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


Raytracer::Calculator::Calculator(int width, int height, std::vector<IEntity *> &entities,
                                  std::vector<std::vector<Component::Color>> &pixels, Raytracer::ISkybox *skybox) : width(width), height(height), entities(entities), pixels(pixels), ambientLightColor(1.0f, 1.0f, 1.0f),
                                  ambientLightIntensity(0.1f), skybox(skybox) {}
