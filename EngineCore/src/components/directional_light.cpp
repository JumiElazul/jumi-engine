#include "EngineCore/components/directional_light.h"
#include "EngineCore/logging/logger.h"

namespace jumi
{

    DirectionalLight::DirectionalLight() { }

    DirectionalLight::~DirectionalLight() { }

	const DirectionalLightParameters& DirectionalLight::get_light_params() const { return _light_parameters; }

	void DirectionalLight::set_ambient(const Vec3& ambient)
	{
		/* JUMI_INFO("DirectionalLight Ambient light being set from {} to {}", _light_parameters.ambient, ambient); */
		_light_parameters.ambient = ambient;
	}

	void DirectionalLight::set_diffuse(const Vec3& diffuse)
	{
		/* JUMI_INFO("DirectionalLight Diffuse light being set from {} to {}", _light_parameters.diffuse, diffuse); */
		_light_parameters.diffuse = diffuse;
	}

	void DirectionalLight::set_specular(const Vec3& specular)
	{
		/* JUMI_INFO("DirectionalLight Specular light being set from {} to {}", _light_parameters.specular, specular); */
		_light_parameters.specular = specular;
	}

	void DirectionalLight::set_specular_strength(float specular_strength)
	{
		/* JUMI_INFO("DirectionalLight SpecularStrength being set from {} to {}", _light_parameters.specular_strength, specular_strength); */
		_light_parameters.specular_strength = specular_strength;
	}

	void DirectionalLight::set_light_intensity(float intensity)
	{
		/* JUMI_INFO("DirectionalLight Light Intensity being set from {} to {}", _light_parameters.intensity, intensity); */
		_light_parameters.intensity = intensity;
	}

}
