#pragma once

#include "core/core.h"
#include "math/vector.h"

namespace jumi
{

    struct DirectionalLightParameters
    {
        Vec3 ambient;
        Vec3 diffuse;
        Vec3 specular;
        float specular_strength;
        float intensity;
    };

	class DirectionalLight
	{
	public:
		DirectionalLight();
		~DirectionalLight();

        const DirectionalLightParameters& get_light_params() const;
        void set_ambient(const Vec3& ambient);
        void set_diffuse(const Vec3& diffuse);
        void set_specular(const Vec3& specular);
        void set_specular_strength(float specular_strength);
        void set_light_intensity(float intensity);

	private:
        DirectionalLightParameters _light_parameters{};
	};

}
