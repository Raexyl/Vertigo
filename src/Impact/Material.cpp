#include "Material.h"

namespace Impact
{
	Material::Material(void)
	{
	}

	Material::Material(float Restitution, float StaticMu, float DynamicMu)
		:restitution(Restitution), staticMu(StaticMu), dynamicMu(DynamicMu)
	{
	}

	Material::~Material(void)
	{
	}
}