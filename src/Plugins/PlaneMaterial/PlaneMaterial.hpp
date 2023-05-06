#pragma once

#include "AMaterial.hpp"

namespace Plugin
{
    class PlaneMaterial : public Raytracer::AMaterial
    {
    public:
        PlaneMaterial(const Component::Color &color1, const Component::Color &color2, double squareSize, double diffuseFactor, double reflectivity);

        ~PlaneMaterial() override = default;

        [[nodiscard]] Component::Color getDiffuse() const override;

        [[nodiscard]] double getSpecular() const override;

        [[nodiscard]] double getShininess() const override;

        [[nodiscard]] double getReflectivity() const override;

    private:
        Component::Color _color1;
        Component::Color _color2;
        double _squareSize;
        double _reflectivity;
        double _diffuseFactor;

        [[nodiscard]] Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                    const Component::Vector3f &lightDirection, double lightIntensity,
                                                    const Component::Color &ambientLightColor, double ambientLightIntensity) const override;
    };
}
