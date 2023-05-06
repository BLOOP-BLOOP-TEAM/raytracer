#pragma once

#include "AMaterial.hpp"

namespace Plugin
{
    class PlaneMaterial : public Raytracer::AMaterial
    {
    public:
        PlaneMaterial(const Component::Color &color1, const Component::Color &color2, float squareSize, float diffuseFactor, float reflectivity);

        ~PlaneMaterial() override = default;

        [[nodiscard]] Component::Color getDiffuse() const override;

        [[nodiscard]] float getSpecular() const override;

        [[nodiscard]] float getShininess() const override;

        [[nodiscard]] float getReflectivity() const override;

    private:
        Component::Color _color1;
        Component::Color _color2;
        float _squareSize;
        float _reflectivity;
        float _diffuseFactor;

        [[nodiscard]] Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                    const Component::Vector3f &lightDirection, float lightIntensity,
                                                    const Component::Color &ambientLightColor, float ambientLightIntensity) const override;
    };
}
