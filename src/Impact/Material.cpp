#include "Material.h"

namespace Impact
{
	Material::Material(void)
	{
	}

	Material::Material(float Restitution, float StaticMu, float DynamicMu, float Density)
		:restitution(Restitution), staticMu(StaticMu), dynamicMu(DynamicMu), density(Density)
	{
	}

	Material::~Material(void)
	{
	}
}